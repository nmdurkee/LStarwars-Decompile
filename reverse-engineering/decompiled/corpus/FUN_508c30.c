/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x508c30; label: FUN_00508c30
 */

void FUN_00508c30(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = param_1;
  piVar1 = *(int **)(param_1 + 0xa8);
  piVar2 = *(int **)(*(int *)(param_1 + 0x58) + 0x1c);
  uVar4 = 0;
  if ((char)piVar2[2] != '\0') {
    param_1 = 0;
    do {
      if ((*(byte *)(*piVar2 + param_1 + 0x58) & 3) == 0) {
        if ((*(byte *)(iVar3 + 0x88) & 0x80) == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = iVar3 + 0x18;
        }
        FUN_00507c50(iVar3,piVar2,*piVar1 + uVar4 * 8,*piVar2 + param_1,param_2,iVar5,param_3);
      }
      param_1 = param_1 + 100;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(byte *)(piVar2 + 2));
  }
  return;
}

