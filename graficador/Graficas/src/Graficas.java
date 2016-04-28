import org.jfree.chart.*;
import org.jfree.data.category.*;
import org.jfree.chart.plot.*;
import javax.swing.*;

public class Graficas {
	public Graficas(){
		DefaultCategoryDataset data = new DefaultCategoryDataset();
		final String ANNO1 = "2010";
		final String ANNO2 = "2011";
		final String ANNO3 = "2012";
		final String ANNO4 = "2013";
		final String ANNO5 = "2014";
		final String ANNO6 = "2015";
		final String ANNO7 = "2016";
		
		data.addValue(1052, ANNO1, "A�os");
		data.addValue(1170, ANNO2, "A�os");
		data.addValue(1186, ANNO3, "A�os");
		data.addValue(1261, ANNO4, "A�os");
		data.addValue(1295, ANNO5, "A�os");
		data.addValue(1295, ANNO6, "A�os");
		data.addValue(1295, ANNO7, "A�os");
//		data.addValue(1052, "PIB", "2010");
//		data.addValue(1170, "PIB", "2011");
//		data.addValue(1186,"PIB", "2012");
//		data.addValue(1261, "PIB", "2013");
//		data.addValue(1295, "PIB", "2014");
//		data.addValue(1295,"PIB", "2015");
//		data.addValue(1295, "PIB", "2016");

		JFreeChart grafica = ChartFactory.createBarChart3D("PIB mexico", "A�os", "billones USD", data, PlotOrientation.VERTICAL, true, true,false);
		//JFreeChart grafica = ChartFactory.createLineChart("PIB mexico","Dias","billones USD",data,PlotOrientation.VERTICAL,true,true,false);
		
		ChartPanel container = new ChartPanel(grafica);
		JFrame ventana = new JFrame("Graficas en java");
		ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ventana.add(container);
		ventana.setSize(600,400);
		ventana.setVisible(true);
		ventana.setLocationRelativeTo(null);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Graficas();
	}

}
