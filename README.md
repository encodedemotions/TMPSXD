# TMPS lab 1 
# Author: Botezat Roman
# Topic:
Practical use of creational design patterns.
# Domain:
Artificial intelligence and neural networks.

# Main classes:

1. Neuron
2. Link
3. Softmax

# Theory:
1.The builder design pattern can greatly help the creation of a neural network by building the layers, one at a time, while using the same connections to the next layer, in an one to all configuration of connections.

2.The prototype design pattern can help the creation of copies  of the neurons and links, by providing a common virtual method, for the interface IObject.

3.The singleton design pattern, can help with the use of softmax where only one instance is counting the parameters needed for a softmax calculation, which can be called everywhere and can be used for any softmax needs.


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





















