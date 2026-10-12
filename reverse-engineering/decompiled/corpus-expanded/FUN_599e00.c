/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x599e00; label: FUN_00599e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00599e00(int *param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  short sVar1;
  int *piVar2;
  size_t _Size;
  int iVar3;
  void *_Dst;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  int local_114;
  int local_110;
  undefined4 *local_10c;
  int *local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_114;
  local_108 = param_1;
  local_10c = param_4;
  if (DAT_00956048 != 0) {
    iVar3 = 0;
    DAT_00955fc4 = DAT_00924890;
    if (0 < DAT_0093b278) {
      do {
        *(undefined4 *)(DAT_00956048 + iVar3 * 4) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_0093b278);
    }
    _Dst = (void *)(*param_3 + 3 & 0xfffffffc);
    *param_3 = (uint)_Dst;
    *(void **)(param_2 + 0x2984) = _Dst;
    _Size = DAT_0093b278 * 4;
    _memset(_Dst,0,_Size);
    *param_3 = *param_3 + _Size;
    local_114 = 0;
    if (*(short *)((int)param_1 + 6) != 0) {
      local_110 = 0;
      do {
        sVar1 = *(short *)(*param_1 + local_110);
        iVar3 = (int)sVar1;
        if (((*(uint *)(iVar3 * 0x120 + 0x94 + DAT_0093b284) & 0x400) == 0) &&
           (iVar4 = FUN_0062df80(iVar3), iVar4 != 0)) {
          *(uint *)(*(int *)(param_2 + 0x2984) + iVar3 * 4) = *param_3;
          *param_3 = *param_3 + 0x18;
          FUN_004f1f10(local_104,"chars\\minikits\\");
          FUN_004f1e80(local_104,*(undefined4 *)(iVar3 * 0x4c + 0xc + DAT_0093b274));
          FUN_004f1e80(local_104,&DAT_0075a204);
          FUN_004f1e80(local_104,*(undefined4 *)(iVar3 * 0x4c + 0xc + DAT_0093b274));
          FUN_004f1e80(local_104,&DAT_0075a1fc);
          *param_3 = *param_3 + 3 & 0xfffffffc;
          if (local_114 < 0x12) {
            uVar5 = *local_10c;
            puVar6 = param_3;
          }
          else {
            puVar6 = &DAT_00924890;
            uVar5 = DAT_00924894;
          }
          uVar5 = FUN_005ef7f0(puVar6,uVar5,local_104);
          **(undefined4 **)(*(int *)(param_2 + 0x2984) + iVar3 * 4) = uVar5;
          *(short *)(*(int *)(*(int *)(param_2 + 0x2984) + iVar3 * 4) + 10) = sVar1;
          piVar2 = *(int **)(*(int *)(param_2 + 0x2984) + iVar3 * 4);
          if (*piVar2 == 0) {
            *(undefined4 *)(*(int *)(param_2 + 0x2984) + iVar3 * 4) = 0;
            *param_3 = *param_3 - 0x18;
            param_1 = local_108;
          }
          else {
            FUN_00599b20(piVar2,10,param_3,local_10c);
            *(undefined4 *)(DAT_00956048 + iVar3 * 4) =
                 *(undefined4 *)(*(int *)(param_2 + 0x2984) + iVar3 * 4);
            param_1 = local_108;
          }
        }
        local_110 = local_110 + 0x1c;
        local_114 = local_114 + 1;
      } while (local_114 < (int)(uint)*(ushort *)((int)param_1 + 6));
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_114);
  return;
}

