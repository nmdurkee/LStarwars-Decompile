/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x603140; label: FUN_00603140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603140(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  int local_608;
  ushort local_604 [256];
  ushort auStack_404 [256];
  ushort auStack_204 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_608;
  local_608 = 0;
  do {
    iVar1 = local_608;
    iVar2 = FUN_006e6b90();
    sVar3 = 0;
    if (0x7fff < iVar2) {
      iVar2 = iVar2 + -0x7fff;
      sVar3 = 1;
      if (0x7fff < iVar2) {
        iVar2 = 0x7fff;
      }
    }
    uVar4 = sVar3 * -0x8000 | (ushort)iVar2;
    local_604[iVar1] = uVar4;
    auStack_404[iVar1] = uVar4;
    auStack_204[iVar1] = uVar4;
    local_608 = iVar1 + 1;
  } while (local_608 < 0x100);
  FUN_006e5cc0(local_604);
  __security_check_cookie(local_4 ^ (uint)&local_608);
  return;
}

