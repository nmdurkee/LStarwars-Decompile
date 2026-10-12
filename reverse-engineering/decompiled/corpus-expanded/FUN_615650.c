/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x615650; label: FUN_00615650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615650(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_11;
  int local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  FUN_0053d5d0(0x20);
  local_11 = 3;
  if (local_c != 0) {
    FUN_004ef660(local_4 + local_c,&local_11,1);
    iVar1 = local_4 + 1 + local_c;
    FUN_004ef660(iVar1,param_1 + 2,2);
    if (local_10 != 0) {
      FUN_00621180(iVar1);
    }
    local_4 = local_4 + 3;
  }
  uVar3 = *(undefined4 *)(param_1 + 8);
  uVar2 = 3;
  iVar1 = local_c;
  if (local_c == 0) {
    FUN_0060f2d0(local_10,0,local_8,local_4,3,uVar3);
  }
  else {
    *(int *)(local_c + 0x4b0) = *(int *)(local_c + 0x4b0) + 1;
  }
  FUN_0060ef10(local_10,iVar1,local_8,local_4,uVar2,uVar3);
  if (local_c != 0) {
    if (1 < *(uint *)(local_c + 0x4b0)) {
      *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(local_c + 0x4b0) = 0;
  }
  return;
}

