/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5557e0; label: FUN_005557e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005557e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *local_18;
  uint local_14;
  int local_10;
  undefined1 local_c [12];
  
  iVar3 = param_2;
  iVar5 = 0;
  local_14 = 0xffffffff;
  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_2 + 0x46e0) != 0)) {
    FUN_005cf5b0(*(undefined4 *)(param_2 + 0x13c),local_c,param_4,0);
    iVar4 = FUN_005cfac0(local_c);
    if (iVar4 != 0) {
      local_10 = 0;
      if (*(char *)(*(int *)(param_2 + 0x128) + 0xf2) != '\0') {
        local_18 = (int *)(*(int *)(param_2 + 0x46e0) + 0x68);
        param_2 = 0;
        do {
          if (param_3 <= iVar5) {
            return iVar5;
          }
          if ((*(byte *)(param_2 + 0xac + *(int *)(iVar3 + 0x46e0)) & 1) != 0) {
            puVar1 = *(undefined4 **)(*local_18 + 0x18);
            bVar2 = true;
            while ((puVar1 != (undefined4 *)0x0 && (bVar2))) {
              iVar4 = FUN_005d0450(local_c,puVar1 + 1);
              if ((iVar4 != 0) &&
                 (iVar4 = FUN_0055a020(*(undefined4 *)(iVar3 + 0x2ac8),local_14,param_4), iVar4 != 0
                 )) {
                local_14 = (uint)*(byte *)(iVar4 + 6);
                *(int *)(param_1 + iVar5 * 4) = iVar4;
                iVar5 = iVar5 + 1;
                bVar2 = false;
              }
              puVar1 = (undefined4 *)*puVar1;
            }
          }
          param_2 = param_2 + 0x304;
          local_18 = local_18 + 0xc1;
          local_10 = local_10 + 1;
        } while (local_10 < (int)(uint)*(byte *)(*(int *)(iVar3 + 0x128) + 0xf2));
      }
      return iVar5;
    }
  }
  return 0;
}

