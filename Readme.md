Monitoramento de Energia Renovável com ESP32 e MQTT

Grupo:Thomaz Morais Neves

Descrição do Projeto:
Este projeto implementa um sistema baseado no ESP32 para monitorar variáveis ambientais, como temperatura e umidade, usando um sensor DHT22. Os dados coletados são enviados via protocolo MQTT para um broker público, permitindo integração com dashboards e sistemas IoT.

O objetivo principal é demonstrar como tecnologias de Edge Computing podem ser aplicadas para monitoramento eficiente e comunicação em tempo real, facilitando o gerenciamento de fontes de energia renovável.

Componentes Utilizados
ESP32: Microcontrolador para processamento e comunicação.
Sensor DHT22: Para medir temperatura e umidade.
Broker MQTT: test.mosquitto.org foi utilizado para transmissão dos dados.
LED: Indicador de status de conexão ao MQTT.
Configuração do Ambiente
Wi-Fi:
Rede: Wokwi-GUEST
Senha: (em branco)
Broker MQTT:
Host: test.mosquitto.org
Porta: 1883
Tópicos:
test/temperature: Para dados de temperatura.
test/humidity: Para dados de umidade.
Plataforma Wokwi:
Link do projeto: https://wokwi.com/projects/416544145129159681
Link do video: https://www.youtube.com/watch?v=kxc4ONC_sT4&ab_channel=thommy