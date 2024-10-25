import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'arith'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob(os.path.join('launch', '*.launch.py'))),
        ('share/' + package_name + '/param', glob(os.path.join('param', '*.yaml')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='test',
    maintainer_email='giraliusr@gmail.com',
    description='Arithmetic final demo',
    license='Apache 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'argument = arith.argument:main',
            'calculator = arith.calculator:main',
            'operator = arith.operator:main'
            'checker = arith.checker:main'
        ],
    },
)
