from setuptools import find_packages
from setuptools import setup

setup(
    name='ex09_package',
    version='0.0.0',
    packages=find_packages(
        include=('ex09_package', 'ex09_package.*')),
)
