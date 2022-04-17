#include "dir_wt_al.hpp"

void set_normal_graph( g_dir_wt_al &gg ){
    gg.add_edge(  0, 1, 10 );
    gg.add_edge(  0, 2, 20);
    gg.add_edge(  1, 3, 30);
    gg.add_edge(  2, 0, 50);
    gg.add_edge(  2, 4, 60);
    gg.add_edge(  3, 3, 70);
    gg.print_graph();

}

void set_cyclic_graph( g_dir_wt_al &gg ){
    gg.add_edge(  0, 1, 10 );
    gg.add_edge(  1, 2, 20);
    gg.add_edge(  1, 3, 30);
    gg.add_edge(  2, 0, 50);
    gg.add_edge(  2, 4, 60);
    gg.add_edge(  3, 4, 70);
    gg.print_graph();
}

void set_dijkstra( g_dir_wt_al &gg ){
    gg.add_edge(  0, 1, 3 );
    gg.add_edge(  0, 2, 4 );
    gg.add_edge(  1, 2, 2 );
    gg.add_edge(  1, 3, 6 );
    gg.add_edge(  2, 3, 3 );
    gg.add_edge(  3, 4, 1 );
    gg.add_edge(  4, 0, 7 );
    gg.print_graph();
}



int main()
{
    g_dir_wt_al gg = g_dir_wt_al(5);
    set_normal_graph( gg );
    gg.dfs_rec( 1 );
    
    g_dir_wt_al gc = g_dir_wt_al(5);
    set_cyclic_graph( gc );
    if( gc.is_cycle() ){ cout << "Cyclic graph" << endl; }
    else { cout << "Non Cyclic graph." << endl;}

    g_dir_wt_al g_dijk = g_dir_wt_al(5);
    set_dijkstra( g_dijk );
    g_dijk.get_short_path( 0 );
    return 0;
}
