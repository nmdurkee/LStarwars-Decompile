/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500b90; label: FUN_00500b90
 */

void FUN_00500b90(void)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int in_EAX;
  int unaff_EDI;
  
  iVar2 = *(int *)(in_EAX + 0x58);
  pfVar1 = (float *)(in_EAX + 0x60);
  if (*(int *)(iVar2 + 0x20) == 0) {
    fVar3 = 0.0;
    *pfVar1 = 0.0;
    *(undefined4 *)(in_EAX + 100) = 0;
  }
  else {
    *pfVar1 = ((*(float **)(iVar2 + 0x20))[3] + **(float **)(iVar2 + 0x20)) * 0.5;
    *(float *)(in_EAX + 100) =
         (*(float *)(*(int *)(iVar2 + 0x20) + 0x10) + *(float *)(*(int *)(iVar2 + 0x20) + 4)) * 0.5;
    fVar3 = (*(float *)(*(int *)(iVar2 + 0x20) + 0x14) + *(float *)(*(int *)(iVar2 + 0x20) + 8)) *
            0.5;
  }
  *(float *)(in_EAX + 0x68) = fVar3;
  if (unaff_EDI != 0) {
    FUN_005b30a0(pfVar1,pfVar1);
  }
  return;
}

