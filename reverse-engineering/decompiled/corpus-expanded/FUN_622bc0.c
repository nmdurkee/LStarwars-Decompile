/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622bc0; label: FUN_00622bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622bc0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_110;
  uint local_10c;
  int local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  if (param_3 == 0) {
    local_110 = 1;
  }
  else {
    if (param_3 != 1) {
      local_110 = (uint)(param_3 == 2) * 2 + -1;
      for (; param_1 != param_2; param_1 = param_1 + 1 + local_108) {
        local_10c = (((((*(byte *)(param_1 + 6) - 0x41) * 0xd + -0x41 + (uint)*(byte *)(param_1 + 5)
                       ) * 0x21 + -0x41 + (uint)*(byte *)(param_1 + 4)) * 0x19 + -0x41 +
                     (uint)*(byte *)(param_1 + 3)) * 0x3d + -0x41 + (uint)*(byte *)(param_1 + 2)) *
                    0x3d + -0x41 + (uint)*(byte *)(param_1 + 1);
        local_108 = FUN_004f1ff0(param_1);
        iVar2 = FUN_004f1ff0(param_1);
        for (iVar2 = iVar2 + 1 + param_1; iVar2 != param_2; iVar2 = iVar2 + 1 + iVar3) {
          uVar1 = (((((*(byte *)(iVar2 + 6) - 0x41) * 0xd + -0x41 + (uint)*(byte *)(iVar2 + 5)) *
                     0x21 + -0x41 + (uint)*(byte *)(iVar2 + 4)) * 0x19 + -0x41 +
                   (uint)*(byte *)(iVar2 + 3)) * 0x3d + -0x41 + (uint)*(byte *)(iVar2 + 2)) * 0x3d +
                  -0x41 + (uint)*(byte *)(iVar2 + 1);
          iVar3 = FUN_004f1ff0(iVar2);
          if (uVar1 < local_10c) {
            iVar4 = 1;
          }
          else {
            iVar4 = -(uint)(local_10c < uVar1);
          }
          if (iVar4 == local_110) {
            FUN_004f1f10(local_104,iVar2);
            FUN_004ef660(param_1 + 1 + iVar3,param_1,iVar2 - param_1);
            FUN_004ef660(param_1,local_104,iVar3 + 1);
            local_10c = uVar1;
            local_108 = iVar3;
          }
        }
      }
      goto LAB_00622dfd;
    }
    local_110 = -1;
  }
  for (; param_1 != param_2; param_1 = param_1 + 1 + iVar3) {
    iVar3 = FUN_004f1ff0(param_1);
    iVar2 = FUN_004f1ff0(param_1);
    for (iVar2 = iVar2 + 1 + param_1; iVar2 != param_2; iVar2 = iVar2 + 1 + iVar4) {
      iVar4 = FUN_004f1ff0(iVar2);
      iVar5 = FUN_004f8b10(param_1 + 7,iVar2 + 7);
      if (iVar5 == local_110) {
        FUN_004f1f10(local_104,iVar2);
        FUN_004ef660(iVar4 + 1 + param_1,param_1,iVar2 - param_1);
        FUN_004ef660(param_1,local_104,iVar4 + 1);
        iVar3 = iVar4;
      }
    }
  }
LAB_00622dfd:
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

