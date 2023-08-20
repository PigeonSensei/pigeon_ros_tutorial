# basic_dynamic_reconfigure_tutorial

basic_dynamic_reconfigure_tutorial provides a reference to a simple use ROS Dynamic Reconfigure

### Run

```bash
rosrun basic_dynamic_reconfigure_tutorial basic_dynamic_reconfigure_node
```

### Parameters
Dynamically Reconfigurable Parameters

The dynamic parameter package is referenced [tutorial_cfgs](https://github.com/PigeonSensei/pigeon_ros_tutorial/tree/master/others/tutorial_cfgs)

~**param_int** (int, defalut: 1, Range: -9 to 9)

~**param_double** (double, default: 1.0, Range: -9.9 to 9.9)

~**param_string** (string, defalut: "Pigeon")

~**param_bool** (bool, default: True)


## Run together to see parameter dynamic changes
```bash
rosrun rqt_reconfigure rqt_reconfigure
```
