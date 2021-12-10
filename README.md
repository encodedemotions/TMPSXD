# Author: Botezat Roman

# Topic:
Practical use of behavioral design patterns.
# Domain:
Artificial intelligence and neural networks.

# LAB3:
# Iterator
layer_iterator.h LayerIterator class, used for the functionality of traversing the neural network layers without exposing its structure.

![image](https://user-images.githubusercontent.com/53918731/145062058-e08d04b8-0173-4a67-a1f9-d864acddf195.png)

Because i used the C++ language, which already has syntax for iterators, i just wrote the LayerIterator as a custom iterator for the Network class, which means that i can use C++ iterator specific syntax:

![image](https://user-images.githubusercontent.com/53918731/145062102-fc2e6855-280c-4fd7-850a-4e26c5dcabbf.png)

Usage of the LayerIterator within the Network class

![image](https://user-images.githubusercontent.com/53918731/145062656-ad2948b9-8046-41dd-bb63-f0be9e2ec6ca.png)

# Motivation:
Because of the non-linear nature of the neural network implementation of layers, no layer has a direct connection to the next layer, which means that if we need to traverse layers, we need to query one of the nodes inside the layer, to get the next layer. This iterator does this for us, and using the begin and end function, we can traverse all the layers in all neural networks with ease.

# Conclussion:
Using the Iterator design pattern we have a way to access all the layers of the neural network with ease, in the case i used, i only printed the weights of the neurons, but because i have a pointer to those neurons, i can virtually do anything with them, where previously i couldn't.

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
