/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1f90; label: FUN_004f1f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_004f1f90(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    if (cVar1 == param_2) break;
    cVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  return param_1;
}

