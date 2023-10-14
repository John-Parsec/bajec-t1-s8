#include "Twitter.hpp"

DataHora::DataHora(){
    this->dataHora = new tm();
}

DataHora::DataHora(int dia, int mes, int ano, int hora, int minuto){
    this->dataHora = new tm();
    this->dataHora->tm_mday = dia;
    this->dataHora->tm_mon = mes;
    this->dataHora->tm_year = ano;
    this->dataHora->tm_hour = hora;
    this->dataHora->tm_min = minuto;

    mktime(this->dataHora);
}

tm* DataHora::getDataHora(){
    return this->dataHora;
}

void DataHora::setDataHora(int dia, int mes, int ano, int hora, int minuto){
    this->dataHora->tm_mday = dia;
    this->dataHora->tm_mon = mes;
    this->dataHora->tm_year = ano;
    this->dataHora->tm_hour = hora;
    this->dataHora->tm_min = minuto;

    mktime(this->dataHora);
}

string DataHora::toString(){
    string data = "";

    if(this->dataHora->tm_mday < 10)
        data += "0";
    
    data += to_string(this->dataHora->tm_mday) + "/";
    
    if(this->dataHora->tm_mon < 10)
        data += "0";
    
    data += to_string(this->dataHora->tm_mon) + "/" + to_string(this->dataHora->tm_year);

    string hora = to_string(this->dataHora->tm_hour) + ":" + to_string(this->dataHora->tm_min);
    return data + " " + hora;
}

DataHora DataHora::dataHoraAtual(){
    time_t now = time(0);

    tm* ltm = localtime(&now);
    
    DataHora dataHora(ltm->tm_mday, ltm->tm_mon, ltm->tm_year, ltm->tm_hour, ltm->tm_min);

    return dataHora;
}

bool DataHora::operator<(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year < dh->tm_year){
        return true;
    }else if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon < dh->tm_mon){
            return true;
        }else if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday < dh->tm_mday){
                return true;
            }else if(this->dataHora->tm_mday == dh->tm_mday){
                if(this->dataHora->tm_hour < dh->tm_hour){
                    return true;
                }else if(this->dataHora->tm_hour == dh->tm_hour){
                    if(this->dataHora->tm_min < dh->tm_min){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool DataHora::operator<=(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year <= dh->tm_year){
        if(this->dataHora->tm_mon <= dh->tm_mon){
            if(this->dataHora->tm_mday <= dh->tm_mday){
                if(this->dataHora->tm_hour <= dh->tm_hour){
                    if(this->dataHora->tm_min <= dh->tm_min){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool DataHora::operator==(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday == dh->tm_mday){
                if(this->dataHora->tm_hour == dh->tm_hour){
                    if(this->dataHora->tm_min == dh->tm_min){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool DataHora::operator>(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year > dh->tm_year){
        return true;
    }else if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon > dh->tm_mon){
            return true;
        }else if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday > dh->tm_mday){
                return true;
            }else if(this->dataHora->tm_mday == dh->tm_mday){
                if(this->dataHora->tm_hour > dh->tm_hour){
                    return true;
                }else if(this->dataHora->tm_hour == dh->tm_hour){
                    if(this->dataHora->tm_min > dh->tm_min){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool DataHora::operator>=(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year >= dh->tm_year){
        if(this->dataHora->tm_mon >= dh->tm_mon){
            if(this->dataHora->tm_mday >= dh->tm_mday){
                if(this->dataHora->tm_hour >= dh->tm_hour){
                    if(this->dataHora->tm_min >= dh->tm_min){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void DataHora::operator=(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    this->dataHora->tm_year = dh->tm_year;
    this->dataHora->tm_mon = dh->tm_mon;
    this->dataHora->tm_mday = dh->tm_mday;
    this->dataHora->tm_hour = dh->tm_hour;
    this->dataHora->tm_min = dh->tm_min;
}

bool DataHora::dataAnterior(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year < dh->tm_year){
        return true;
    }else if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon < dh->tm_mon){
            return true;
        }else if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday < dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool DataHora::dataIgual(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday == dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool DataHora::dataPosterior(DataHora* dataHora){
    tm* dh = dataHora->getDataHora();

    if(this->dataHora->tm_year > dh->tm_year){
        return true;
    }else if(this->dataHora->tm_year == dh->tm_year){
        if(this->dataHora->tm_mon > dh->tm_mon){
            return true;
        }else if(this->dataHora->tm_mon == dh->tm_mon){
            if(this->dataHora->tm_mday > dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}