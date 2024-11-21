/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:57 by eviscont          #+#    #+#             */
/*   Updated: 2024/11/21 15:50:41 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	//Initialize Data object
	Data	objData;
	objData.data1 = 21;
	objData.data2 = 42;
	objData.data3 = "str 21";
	objData.data4 = "str 42";

	//Serialize Data object
	uintptr_t	serData = Serializer::serialize(&objData);
	std::cout << "Data Address: " << &objData << std::endl;
	std::cout << "Serialized: " << serData << std::endl;

	//Deserialize Data object
	Data *desData = Serializer::deserialize(serData);
	std::cout << "Deserialized: " << &desData << std::endl;

	//Check Data content, before and after serialization
	std::cout << "Data1 before: " << objData.data1 << std::endl;
	std::cout << "Data1 after: " << desData->data1 << std::endl;
	std::cout << "Data2 before: " << objData.data2 << std::endl;
	std::cout << "Data2 after: " << desData->data2 << std::endl;
	std::cout << "Data3 before: " << objData.data3 << std::endl;
	std::cout << "Data3 after: " << desData->data3 << std::endl;
	std::cout << "Data4 before: " << objData.data4 << std::endl;
	std::cout << "Data4 after: " << desData->data4 << std::endl;

	return 0;
}
