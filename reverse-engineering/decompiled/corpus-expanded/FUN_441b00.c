/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441b00; label: FUN_00441b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441b00(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float fVar1;
  int iVar2;
  
  if (((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (iVar2 = **(int **)(param_3 + 0xd0), iVar2 != 0)) &&
      ((param_5 != -1 && ((*(char *)(iVar2 + 0x281) != '\0' || (*(char *)(iVar2 + 0x282) != '\0'))))
      )) && ((*(short *)(iVar2 + 0x27e) == param_5 &&
             (fVar1 = *(float *)(*(int *)(*(short *)(iVar2 + 0x27e) * 0x6c + 0x40 +
                                         *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
             fVar1 < *(float *)(iVar2 + 0x60) != (fVar1 == *(float *)(iVar2 + 0x60)))))) {
    return (float10)1;
  }
  return (float10)0;
}

