
void Map::buildMatrix(){
    m_data = new char *[m_rows];
    for(int i = 0; i < m_rows; i++)
    {
        m_data[i] = new char[m_cols];
    }
}

void Map::deleteMatrix(){
    for(int i = 0; i < m_rows; i++){
        delete[] m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
}

void Map::fillMatrix(){
    for(int r = 0; r < m_rows; r++){
        for(int c = 0; c < m_cols; c++){
            if ((c == 0) || (c == (m_cols - 1))){
                m_data[r][c] = '|';
            }
            else if ((r == 0) || (r == (m_rows - 1))){
                m_data[r][c] = '-';
            }
            else{
                m_data[r][c] = ' ';
            }
        }
    }

}

void Map::printMatrix(){
    for(int r = 0; r < m_rows; r++){
        for(int c = 0; c < m_cols; c++){
            cout << m_data[r][c] << " ";
        }
        cout << endl;
    }
}

void Map::placeMountains(){
    int rowLength = (rand() % 3) + 6;
    int colLength = (rand() % 3) + 6;
    int startRow = rand() % (m_rows - 1); //Top left corner
    int startCol = rand() % (m_cols - 1);

    if(startRow + rowLength > (m_rows - 1)){
        rowLength = (m_rows - 1) - startRow;
    }
    if(startCol + colLength > (m_cols - 1)){
        colLength = (m_cols - 1) - startCol;
    }
    for(int r = startRow; r < (startRow + rowLength); r++){
        for(int c = startCol; c < (startCol + colLength); c++){
            m_data[r][c] = 'M';
        }
    }

}
