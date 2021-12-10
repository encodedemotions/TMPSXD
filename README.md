# Author: Botezat Roman
# Topic:
Practical use of behavioral design patterns.
# Domain:
Artificial intelligence and neural networks.

# LAB2:
# Decorator:
dnetwork.h DNetwork class(decorator network), used for the added functionality of printing the neural network's layers without modifying the base class.

![image](https://user-images.githubusercontent.com/53918731/141479912-a15ee844-9ba7-467d-8cab-449c4b60cf3e.png)

Usage: (Network does not have a print_all_layers() function)

![image](https://user-images.githubusercontent.com/53918731/141479984-55470081-0084-4a6d-9551-80f5800708ee.png)

# Facade:
fsoftmax.h softmax_layer function (facade for softmax), used for simplifying the softmax interface.

![image](https://user-images.githubusercontent.com/53918731/141480489-f294bd90-e88c-4b44-915a-bbaebc8fe677.png)

Usage: Adds the ability to call the softmax singleton to easily apply the softmax transformation for an array of numbers.

![image](https://user-images.githubusercontent.com/53918731/141480567-5a2213d3-32e2-438f-82bb-bbe49235d2d7.png)

# Composite:
link.h Link class, used as a composite for neurons, by calling all children' on_send(), or on_receive() functions.

![image](https://user-images.githubusercontent.com/53918731/141480872-3994f3bc-e5e6-492b-9a47-b38cf146a569.png)

Usage: Call the same function with the same arguments for multiple neurons in a layer using a link.

![image](https://user-images.githubusercontent.com/53918731/141481122-e00b714f-89e4-446c-9b1b-1c2cd34933f7.png)


# LAB1:
# To instantiate a neuron, we can use:

1. NeuronBuilder - Builder pattern.

![image](https://user-images.githubusercontent.com/53918731/135215516-b6969088-3970-4d41-82e1-dafc8f01f079.png)
 
2. IObject::copy() virtual method - Prototype pattern.

![image](https://user-images.githubusercontent.com/53918731/135215448-15eaff36-116c-4e03-9f1e-cf6f86437157.png)


# To instantiate a link, we can use:

1. IObject::copy() virtual method - Prototype pattern.

![image](https://user-images.githubusercontent.com/53918731/135215302-45fb322a-3ecb-4af1-9a9e-8ca4d135645a.png)


# To instantiate a Softmax, we can use:

1. Softmax::getInstance() static method - Singleton pattern.

![image](https://user-images.githubusercontent.com/53918731/135215621-95347232-6fe0-4899-a199-f916bae7bb85.png)

# Results:
1. Easy network creation, thanks to builder pattern:

![image](https://user-images.githubusercontent.com/53918731/135218307-8553f27d-3242-405b-8b5f-656d6b18c799.png)

2. Easy softmax usage, thanks to singleton pattern:

![image](https://user-images.githubusercontent.com/53918731/135218369-9b5733a2-6504-4dfa-a94a-70017fb7e974.png)

3. Easy copying of neurons and links, thanks to the prototype pattern.

![image](https://user-images.githubusercontent.com/53918731/135220009-3c8316ed-2471-43a6-80c7-18380c6cacaf.png)





















