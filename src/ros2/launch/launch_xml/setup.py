from setuptools import find_packages
from setuptools import setup

package_name = 'launch_xml'

setup(
    name=package_name,
    version='1.0.9',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Ivan Paunovic',
    author_email='ivanpauno@ekumenlabs.com',
    maintainer='Aditya Pande, Michel Hidalgo',
    maintainer_email='aditya.pande@openrobotics.org, michel@ekumenlabs.com',
    url='https://github.com/ros2/launch',
    download_url='https://github.com/ros2/launch/releases',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='XML frontend for the `launch` package.',
    long_description=(
        'This package provides XML parsing ability to `launch-frontend` package.'
    ),
    license='Apache License, Version 2.0',
    tests_require=['pytest'],
    entry_points={
        'launch.frontend.parser': [
            'xml = launch_xml:Parser',
        ],
    }
)
