/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x402910; label: FUN_00402910
 */

void FUN_00402910(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  if (*(int *)(param_1 + 0x509c) == 0) {
    iVar3 = FUN_006217e0();
    iVar4 = FUN_006217e0();
    iVar6 = *(int *)(param_1 + 0x5098);
    iVar5 = 0;
    *(int *)(param_1 + 0x509c) = iVar4;
    if (0 < iVar4) {
      do {
        FUN_006216f0(iVar6,0x10);
        FUN_00621900(iVar6 + 0x10);
        uVar2 = FUN_00621860();
        *(undefined2 *)(iVar6 + 0x5c) = uVar2;
        cVar1 = FUN_006218e0();
        *(char *)(iVar6 + 0x5e) = cVar1;
        if (cVar1 == '\0') {
          *(undefined1 *)(iVar6 + 0x5e) = 1;
        }
        else if (cVar1 == -1) {
          *(undefined1 *)(iVar6 + 0x5e) = 0xff;
        }
        if (iVar3 == 2) {
          cVar1 = FUN_006218c0();
          FUN_006216f0(local_14,(int)cVar1);
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x74;
      } while (iVar5 < *(int *)(param_1 + 0x509c));
    }
    __security_check_cookie(local_4 ^ (uint)local_14);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

