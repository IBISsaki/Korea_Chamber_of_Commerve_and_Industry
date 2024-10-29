from setuptools import find_packages, setup

package_name = 'ros2env'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'ros2cli'],
    zip_safe=True,
    maintainer='test',
    maintainer_email='giraliusr@gmail.com',
    description='TODO: Package description',
    license='Apache 2.0',
    tests_require=['pytest'],
    entry_points={
        'ros2cli.command': [
            'env = ros2env.command.env:EnvCommand'
        ],
        'ros2cli.extension_point': [
            'ros2env.verb = ros2env.verb:VerbExtension'
        ],
        'ros2env.verb': [
            'list = ros2env.verb.list:ListVerb',
            'set = ros2env.verb.set:SetVerb'
        ]
    },
)