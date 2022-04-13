import time
from tkinter import BROWSE
from turtle import back
from urllib.request import urlopen
from regex import R
import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

options = webdriver.ChromeOptions()
options.add_argument('headless')
options.add_argument("no-sandbox")
options.add_argument("disable-gpu") 
options.add_argument("lang=ko_KR")
options.add_experimental_option('excludeSwitches', ['enable-logging'])
# options.headless = True
browser = webdriver.Chrome('chromedriver.exe', options=options)
url = "https://www.joongwongolf.co.kr/"
browser.get(url)

def first():
    browser.switch_to.window(browser.window_handles[2])
    browser.close() 
    browser.switch_to.window(browser.window_handles[1])
    browser.close() 
    browser.switch_to.window(browser.window_handles[0])

    user_id = 'ran12266'
    user_pass = 'ran12266***'
    browser.find_element(By.XPATH, "//*[@id='header']/div/div[1]/a[1]").send_keys(Keys.ENTER) #로그인창
    time.sleep(0.5)
    browser.find_element(By.XPATH, "//*[@id='login_id']").send_keys(user_id) #id
    time.sleep(0.5)
    browser.find_element(By.XPATH, "//*[@id='login_pw']").send_keys(user_pass) #비번
    time.sleep(0.5)
    browser.find_element(By.XPATH, "//*[@id='login']/a").send_keys(Keys.ENTER)
    time.sleep(0.5)
    browser.switch_to.alert.accept()
    time.sleep(1.5)
    browser.switch_to.window(browser.window_handles[2])
    browser.close() 
    browser.switch_to.window(browser.window_handles[1])
    browser.close() 
    browser.switch_to.window(browser.window_handles[0])
    

def search():
    browser.find_element(By.XPATH, "//*[@id='gnb_reservation']/h2/a").send_keys(Keys.ENTER) #예약창
    time.sleep(0.5)
    browser.find_element(By.XPATH, "//*[@id='calendar_view_ajax_1']/table/tbody/tr[5]/td[1]/a").send_keys(Keys.ENTER) #날짜
    soup = BeautifulSoup(browser.page_source, "lxml")
    end = soup.select("#input_ajax > dl")[0]
    dt_end = end.select('dt')[0]
    dt_text = dt_end.get_text()
    if dt_text == "예약이 마감되었습니다.":
        time.sleep(5)
        search()        
    browser.find_element(By.XPATH, "//*[@id='timelist_course_ajax']/ul/li[2]/a").send_keys(Keys.ENTER) #신라 
    time.sleep(0.3)   
    soup1 = BeautifulSoup(browser.page_source, "lxml")
    silla = soup1.select("#tab1 > table > tbody > tr")
    for tr in silla:
        no_date1 = tr.select('td')[0]
        second = no_date1.get_text()        
        time.sleep(0.5)
        if second == "Tee-off 타임이 없습니다.":
            search_Backjae()                                                      
        else: #신라예약
            date1 = tr.select('td')[2]
            second1 = date1.get_text()[0]
            second2 = date1.get_text()[1]
            second3 = date1.get_text()[3]
            second4 = date1.get_text()[4]
            final = second1+second2+second3+second4 #시간
            final_Time = final.zfill(4)
            change = int(final_Time)          
            if 1150 < change < 1400:
                browser.find_element(By.XPATH, "//*[@id='timeresbtn_1_{0}']".format(final_Time)).send_keys(Keys.ENTER) #예약창
                try:
                    WebDriverWait(browser, 5).until(EC.alert_is_present())
                    browser.switch_to.alert.accept()
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
                except:
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
            else:
                search_Backjae()    
            
def search_Backjae():
    time.sleep(0.5)
    browser.find_element(By.XPATH, "//*[@id='timelist_course_ajax']/ul/li[3]/a").send_keys(Keys.ENTER) #백제
    time.sleep(0.3)
    soup2 = BeautifulSoup(browser.page_source, "lxml")
    new_Backjae = soup2.select("#tab2 > table > tbody > tr")           
    for tr in new_Backjae:        
        no_date2 = tr.select('td')[0]
        first = no_date2.get_text()
        if first == "Tee-off 타임이 없습니다.":
            search_Goguryeo()        
        else:
            date2 = tr.select('td')[2]
            second1 = date2.get_text()[0]
            second2 = date2.get_text()[1]
            second3 = date2.get_text()[3]
            second4 = date2.get_text()[4]
            final = second1+second2+second3+second4 #시간
            final_Time = final.zfill(4)
            change = int(final_Time)
            if 0000 < change < 1400: #백제예약
                browser.find_element(By.XPATH, "//*[@id='timeresbtn_2_{0}']".format(final_Time)).send_keys(Keys.ENTER) #예약창으로
                try:
                    WebDriverWait(browser, 5).until(EC.alert_is_present())
                    browser.switch_to.alert.accept()
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
                except:
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
            else:
                search_Goguryeo()
    
def search_Goguryeo():
    browser.find_element(By.XPATH, "//*[@id='timelist_course_ajax']/ul/li[4]/a").send_keys(Keys.ENTER) #고구려
    soup3 = BeautifulSoup(browser.page_source, "lxml")
    new_Gogu = soup3.select("#tab3 > table > tbody > tr")
    for tr in new_Gogu:
        no_date3 = tr.select('td')[0]
        first = no_date3.get_text()        
        if first == "Tee-off 타임이 없습니다.":
            search()
        else:
            date3 = tr.select('td')[2]
            second1 = date3.get_text()[0]
            second2 = date3.get_text()[1]
            second3 = date3.get_text()[3]
            second4 = date3.get_text()[4]
            print(second1)
            print(second2)
            print(second3)
            print(second4)
            final = second1+second2+second3+second4 #시간
            final_Time = final.zfill(4)
            change = int(final_Time)
            print(change)
            if 0000 < change < 1400: #고구려예약
                browser.find_element(By.XPATH, "//*[@id='timeresbtn_3_{0}']".format(change)).send_keys(Keys.ENTER)
                try:
                    WebDriverWait(browser, 5).until(EC.alert_is_present())
                    browser.switch_to.alert.accept()
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
                except:
                    browser.find_element(By.XPATH, "//*[@id='golfdataform']/div/button[1]").send_keys(Keys.ENTER)
                    browser.switch_to.alert.accept()
            else:
                time.sleep(666)
                search() 
      
first()
search()  
