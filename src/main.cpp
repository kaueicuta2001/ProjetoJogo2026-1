int main()
{
    Plataforma plat(20, false, 1, 2, 60);
    plat.executar();
    plat.salvar();

    ObstDificil hard(50, true, 5, 6, 40);
    hard.executar();
    hard.salvar();

    ObstMedio medium(62.5, false, 6, 8, 50);
    medium.executar();
    medium.salvar();

    Jogador jgd(35, 10, 50, 50, 47);
    jgd.executar();
    jgd.salvar();

    InimigoEasy easy(5.9, 23, 5, 6, 4, 69);
    easy.executar();
    easy.salvar();

    InimigoMedio mediumini(60, 24, 8, 45, 65, 4647);
    mediumini.executar();
    mediumini.salvar();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Projeto Jogo");//RenderWindow é a classe que representa a janela do jogo, e é nela que tudo será desenhado.
    //O primeiro parâmetro é o tamanho da janela, e o segundo é o título da janela.

    sf::RectangleShape jogador(sf::Vector2f(50,50));//RectangleShape é a classe que representa um retângulo.
    jogador.setFillColor(sf::Color::Green);//setFillColor é a função que define a cor do retângulo, e sf::Color é a classe que representa uma cor.
    jogador.setPosition(50, 50);//setPosition é a função que define a posição do retângulo, e os parâmetros são as coordenadas x e y.

    while (window.isOpen())//verifica se a janela está aberta
    {
        sf::Event event;//Event é a classe que representa um evento, como um clique do mouse ou uma tecla pressionada.
        while (window.pollEvent(event))//verifica se há algum evento durante a execução do jogo
        {
            if (event.type == sf::Event::Closed)//se clicar no x da janela
                window.close();//fecha a janela
            
            else if(event.type == sf::Event::KeyPressed)//se pressionar uma tecla
            {
                if (event.key.code == sf::Keyboard::Escape)//se a tecla for escape
                    window.close();//fecha a janela
            }
        }

        window.clear();

        // Desenhar aqui
        window.draw(jogador);//draw é a função que desenha o retângulo na janela, e o parâmetro é o objeto que queremos desenhar.

        window.display();
    }

    return 0;
}