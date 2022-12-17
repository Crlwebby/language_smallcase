# coding=utf-8

import os
os.chdir(os.path.dirname(__file__))
num = 0
def scan_files(directory,ext) :
    #file_list = []
    global num
    dir_list = os.listdir(directory)
    for cur_file in dir_list:
        path = os.path.join(directory, cur_file)
        if os.path.isfile(path):
            temp = os.path.split(path)[1].split('.')
            if len(temp)>1 and temp[1] == ext:
                num = num + 1
                print("{0}".format(cur_file))
        if os.path.isdir(path):
            scan_files(path,ext)
            

if __name__ == "__main__":
    scan_files("D:\data\microsoft\文档\我的文档\电子书",'pdf')
    print("finished")
    print("{0} pdf has been scaned".format(num))