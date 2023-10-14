**Roteiro, deslocamento e pernoite** são eventos, pois possuem duração prevista. Logo, podem ser organizados usando herança, na qual `evento` é a superclasse que vai agrupar os comportamentos gerais de um evento.

**Cliente** e **dependentes** possuem um relacionamento diferente, pois neste sistema não existe a necessidade de armazenar dependentes sem o seu responsável. Nesse caso, temos a composição, pois dependentes só podem existir com um cliente. Para implementar isso, basta adicionar na classe `dependentes` um atributo `Cliente` e fazer o construtor receber o `Cliente` como parâmetro.

**Evento** e **pacote** se complementam, mas não têm a restrição de um só existir com o outro. Dessa forma, temos uma agregação.
