# th-perceptron

Pequena implementação em c++ do execício número 4 do segundo capítulo do livro:  

###### `Redes Neurais Artificiais: Teoria e Aplicações`  
*Antônio de Pádua Braga*  
*André Ponce de Leon F. de Carvalho*  
*Teresa Bernarda Ludemir*  

---

> 4 - Implementar em uma linguagem de programação qualquer um discriminador de dois caracteres utilizando um único neurônio MCP e a regra de aprendizado do perceptron. O neurônio MCP, com *n* entradas, deverá discriminar os caracteres **T** e **H** descritos na forma de uma matrix *i* por *j*, em que *ij = n*. Usar *n* pelo menos igual a 9 (em que *i = j = 3*). O neurônio deverá ser treinado para responder com 1 quando o vetor de entrada for igual a **T** e 0 quando for igual a **H**. Fornecer os seguintes resultados:

> a. Curva de erro do neurônio durante o aprendizado  
> b. Respostas do neurônio quando a entrada for igual a **T** e **H**.  
> c. Comentar a capacidade de generalização da rede: qual a resposta para caracteres não-conhecidos? Testar com os caracteres **T** e **H** distorcidos  