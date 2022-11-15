package org.buaa.utils;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class PropertiesUtils {
    public static Properties load(String path) throws IOException {
        Properties properties = new Properties();
        FileReader reader = new FileReader(path);
        properties.load(reader);
        return properties;
    }
}
