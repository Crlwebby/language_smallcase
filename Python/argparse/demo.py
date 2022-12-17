import argparse

parser = argparse.ArgumentParser(description='命令行中输入一个参数')

parser.add_argument('--integers', required=True, help='传入的数字', default='123')
args = parser.parse_args()

print(args.__dict__)