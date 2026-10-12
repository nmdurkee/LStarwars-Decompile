/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441b70; label: FUN_00441b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441b70(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) && (DAT_0093d810 != 0)) &&
       ((iVar1 = **(int **)(param_3 + 0xd0), *(char *)(iVar1 + 0x281) != '\0' ||
        (*(char *)(iVar1 + 0x282) != '\0')))) &&
      ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) &&
     ((*(short *)(iVar1 + 0x27e) != -1 &&
      (*(short *)(iVar1 + 0x27e) == *(short *)(DAT_0093d810 + 0x27e))))) {
    return (float10)1;
  }
  return (float10)0;
}

