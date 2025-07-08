# chesse

<div align="center">
`chesse` is a chessboard implementation, which features two players and all the pieces a traditional chess game has to offer. It also includes unit and coverage tests to verify if all its functionality has to offer is working accordingly.
</div>

## Table of Contents :pushpin:

* [Dependencies](#dependencies-memo)
    - [C.Make 3.24](#cmake-324)
    - [LCOV](#lcov)
    - [GCOV](#gcov)
* [HowTo](#howto-rocket)
    -[Configuring VSCode IDE](#configuring-vscode-ide)
    -[Enabling LCOV tests](#enabling-lcov-tests)

## Dependecies :memo:

In order to use `chesse` and its features, you have to acquire the following prerequisites beforehand:

### CMake 3.24

You may install the package on its official [page](https://cmake.org/). Higher versions are also supported.

- For **Linux**

    Ubuntu/Debian users can install the package by using the command **apt-get** on their Linux shell.

    It is also recommended to install by using the standard package manager offered by your prefered distro.

- For **MacOS**

    Mac users may obtain the package through [MacPorts](https://www.macports.org/) or [Homebrew](https://brew.sh/).

### LCOV

- For **Linux**

    Ubuntu/Debian users can install the package by using the command below on their Linux Shell:

    ```
    sudo apt-get install lcov
    ``` 

- For **MacOS (MacPorts)**

    Mac users may obtain the package by using the following:

    ```
    sudo port install lcov
    ```

### GCOV

If gcov is not already installed on your machine, you may use the commands below.

- For **Linux**

    Ubuntu/Debian users can install the package by using the command below on their Linux Shell:

    ```
    sudo apt-get install gcov
    ``` 

- For **MacOS**

    Mac users may obtain the package by using the following:

    ```
    sudo port install gcov
    ```

## HowTo :rocket:

### Configuring VSCode IDE

At first, create a folder named **.vscode** to `chesse` root path. 

```shell
cd chesse
md .vscode
```

Copy whole folder content **chesse/doc/vscode_sample** into the created **.vscode** folder.

```shell
cp doc/.vscode_sample/* ./vscode
```

The **launch.json** file already has configurations for all supported `chesse` operating systems (Mac, Windows and Linux).

### Enabling LCOV tests

**By default, `chesse` doesn't build its lcov tests**. 

If you would like to check the coverage tests report, it is necessary to change the **settings.json** file on your **.vscode** folder from **false** to **true**.

>[!IMPORTANT]
>For now, `chesse` does **NOT** have coverage tests support for Windows.