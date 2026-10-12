/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6dfa70; label: FUN_006dfa70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dfa70(undefined4 param_1)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  float local_608;
  ushort local_604 [256];
  ushort local_404 [256];
  ushort local_204 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_608;
  local_608 = 0.0;
  do {
    fVar1 = local_608;
    local_608 = (float)(int)local_608 / 255.0;
    FUN_005be630(local_608,param_1);
    iVar3 = FUN_006e6b90();
    if (0xfffe < iVar3) {
      iVar3 = 0xffff;
    }
    local_608 = (float)((int)fVar1 + 1);
    uVar2 = (ushort)iVar3 & (iVar3 < 1) - 1;
    local_604[(int)fVar1] = uVar2;
    local_604[(int)fVar1 + 0x100] = uVar2;
    local_604[(int)fVar1 + 0x200] = uVar2;
  } while (local_608 != 3.58732e-43);
  FUN_006e5cc0(local_604);
  __security_check_cookie(local_4 ^ (uint)&local_608);
  return;
}

