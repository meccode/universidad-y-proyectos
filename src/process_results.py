import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

# Crear carpeta de salidas si no existe
os.makedirs('results/figures', exist_ok=True)

# 1. Cargar datos
df = pd.read_csv('results/benchmark_results.csv')

# Mapeo de patrones para nombres claros en gráficos
pattern_names = {
    1: 'Aleatorio',
    2: 'Ascendente',
    3: 'Descendente',
    4: 'Casi Ordenado',
    5: 'Con Duplicados'
}
df['Pattern_Name'] = df['Pattern'].map(pattern_names)

# 2. Generar Estadística Descriptiva
stats = df.groupby(['Algorithm', 'Pattern_Name', 'Size']).agg(
    Mean_Time=('Time_ms', 'mean'),
    Std_Time=('Time_ms', 'std'),
    Median_Time=('Time_ms', 'median'),
    Min_Time=('Time_ms', 'min'),
    Max_Time=('Time_ms', 'max'),
    Mean_Comparisons=('Comparisons', 'mean')
).reset_index()

# Guardar resumen estadístico en CSV
stats.to_csv('results/summary_statistics.csv', index=False)
print("¡Estadísticas descriptivas guardadas en results/summary_statistics.csv!")

# 3. Gráfico 1: Escalabilidad (n vs. Tiempo) con escala logarítmica en ambos ejes
plt.figure(figsize=(10, 6))
sns.lineplot(data=df, x='Size', y='Time_ms', hue='Algorithm', style='Pattern_Name', markers=True, dashes=False)
plt.xscale('log')
plt.yscale('log')  # <-- Aplicado para resolver la compresión visual
plt.title('Escalabilidad Asintótica: Tamaños de Muestra (n) vs. Tiempo (ms) [Log-Log]')
plt.xlabel('Tamaño del Arreglo (n) [Escala Logarítmica]')
plt.ylabel('Tiempo (ms) [Escala Logarítmica]')
plt.grid(True, which="both", ls="--")
plt.savefig('results/figures/figura1_n_vs_tiempo.png', dpi=300, bbox_inches='tight')
plt.close()

# 4. Gráfico 2: Boxplot Comparativo para n=100000
df_large = df[df['Size'] == 100000]
plt.figure(figsize=(12, 6))
sns.boxplot(data=df_large, x='Pattern_Name', y='Time_ms', hue='Algorithm')
plt.title('Distribución de Tiempos de Ejecución para n = 100,000')
plt.xlabel('Patrón de Entrada')
plt.ylabel('Tiempo (ms)')
plt.yscale('log') # Para apreciar diferencias exponenciales si existen
plt.grid(True, ls="--")
plt.savefig('results/figures/figura2_boxplot_100k.png', dpi=300, bbox_inches='tight')
plt.close()

print("¡Gráficos generados con éxito en results/figures/!")