/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6355f0; label: FUN_006355f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006355f0(int param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    puVar2 = (ushort *)(param_1 + 0x6c);
    do {
      if (((char)puVar2[-8] != '\0') && (*puVar2 == param_2)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x46;
    } while (iVar1 < 0x80);
  }
  return -1;
}

