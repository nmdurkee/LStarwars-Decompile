/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x44b0e0; label: FUN_0044b0e0
 */

undefined4
FUN_0044b0e0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) &&
     (((iVar2 = *piVar1, param_6 != 0 && (*(undefined4 *)(iVar2 + 0xed8) = 0x4e6e6b28, param_5 != 0)
       ) && (iVar3 = FUN_004f8b10(*param_4,"default"), iVar3 != 0)))) {
    fVar4 = (float10)FUN_005147c0(param_2,*param_4);
    *(float *)(iVar2 + 0xed8) = (float)fVar4;
  }
  return 1;
}

