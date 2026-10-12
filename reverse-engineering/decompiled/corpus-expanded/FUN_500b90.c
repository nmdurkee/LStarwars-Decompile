/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500b90; label: FUN_00500b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

