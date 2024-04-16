# Specs
    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU

### Strategy 1

##### Vector
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Skaitymas uztruko:           | 0.015444s   | 0.166344s      | 1.59188s        | 15.4619s         | 165.159s          |
| Rusiavimas uztruko:          | 0.006081s  | 0.0552494s     | 0.538313s       | 6.18915s         | 60.0473s          |
| Studentu skirstymas uztruko: | 0.002001s | 0.00835907s    | 0.0876151s      | 1.10855s         | 11.3426s          |

##### List
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0202555s   | 0.166206s      | 1.56521s        | 15.9532s         | 166.259s          |
| Time taken to sort data      | 0.00403285s  | 0.0604099s     | 0.799202s       | 10.1229s         | 114.698s          |
| Time taken to divide students| 0.000769389s | 0.0074186s     | 0.0936631s      | 0.969208s        | 9.71874s          |

##### Deque
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0232768s   | 0.163882s      | 1.56918s        | 16.0526s         | 164.046s          |
| Time taken to sort data      | 0.00670575s  | 0.0587848s     | 0.616905s       | 6.67419s         | 59.6123s          |
| Time taken to divide students| 0.000968202s | 0.00842794s    | 0.09097s        | 0.964875s        | 10.6465s          |


### Strategy 2

##### Vector
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0209572s   | 0.163544s      | 1.6192s         | 15.753s          | 165.401s          |
| Time taken to sort data      | 0.00586344s  | 0.0549243s     | 0.591112s       | 5.76212s         | 56.8978s          |
| Time taken to divide students| 0.000764175s | 0.00705321s    | 0.0999966s      | 0.880787s        | 9.8865s           |

##### List
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0234302s   | 0.163621s      | 1.61604s        | 16.6939s         | 156.007s          |
| Time taken to sort data      | 0.00382998s  | 0.0571905s     | 0.777995s       | 10.065s          | 111.851s          |
| Time taken to divide students| 0.000549503s | 0.00595599s    | 0.0938836s      | 1.04645s         | 10.5176s          |

##### Deque
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0203225s   | 0.162119s      | 1.59787s        | 16.8757s         | 156.693s          |
| Time taken to sort data      | 0.00546757s  | 0.0559585s     | 0.588068s       | 6.6712s          | 58.1088s          |
| Time taken to divide students| 0.00081878s  | 0.00721679s    | 0.0840498s      | 0.953856s        | 9.93604s          |


### Strategy 3
#### Vector
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0234721s    | 0.16696s       | 1.63409s        | 15.7987s         | 170.903s          |
| Time taken to sort data           | 0.00544238s   | 0.0560425s     | 0.559435s       | 6.42106s         | 57.2009s          |
| Time taken to divide students     | 0.0011887s    | 0.00826525s    | 0.0977371s      | 1.02714s         | 11.0873s          |

#### List
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0208152s    | 0.165998s      | 1.54981s        | 15.6058s         | 153.042s          |
| Time taken to sort data           | 0.00485212s   | 0.0577385s     | 0.730288s       | 10.3186s         | 111.985s          |
| Time taken to divide students     | 0.000438091s  | 0.00416862s    | 0.0714406s      | 0.814364s        | 8.21541s          |

#### Deque
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0215544s    | 0.162368s      | 1.63176s        | 16.2804s         | 154.024s          |
| Time taken to sort data           | 0.00574811s   | 0.0559582s     | 0.577608s       | 6.46955s         | 58.3943s          |
| Time taken to divide students     | 0.00100723s   | 0.00996933s    | 0.117997s       | 1.33683s         | 13.8873s          |

