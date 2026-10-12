/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579c60; label: FUN_00579c60
 */

void FUN_00579c60(int param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  size_t _Size;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  uVar5 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x104) = uVar5;
  *(uint *)(param_1 + 0x2ac4) = uVar5;
  _Size = DAT_00951bb4 * 4;
  *(uint *)(param_1 + 0x104) = uVar5 + _Size;
  _memset(*(void **)(param_1 + 0x2ac4),0,_Size);
  if ((DAT_00951bb0 != 0) && (local_48 = 0, 0 < DAT_00951bb4)) {
    iVar11 = 0;
    do {
      iVar10 = local_48;
      sVar1 = *(short *)(iVar11 + 0xe + DAT_00951bb0);
      if (((sVar1 == -1) || (*(int *)(param_1 + 0x120) == (int)sVar1)) &&
         ((sVar1 = *(short *)(iVar11 + 0xc + DAT_00951bb0), sVar1 == -1 ||
          (*(int *)(param_1 + 0x11c) == (int)sVar1)))) {
        piVar6 = *(int **)(iVar11 + DAT_00951bb0);
        if (piVar6 == (int *)0x0) {
          piVar6 = (int *)(param_1 + 0x13c);
        }
        iVar4 = *piVar6;
        if (iVar4 != 0) {
          uVar7 = FUN_005d0690(iVar4,*(undefined4 *)(iVar11 + 4 + DAT_00951bb0));
          *(undefined4 *)(*(int *)(param_1 + 0x2ac4) + iVar10 * 4) = uVar7;
          piVar6 = (int *)(*(int *)(param_1 + 0x2ac4) + iVar10 * 4);
          if ((*piVar6 != 0) &&
             (((uVar2 = *(ushort *)(iVar11 + 8 + DAT_00951bb0), uVar2 != 0 &&
               (iVar10 = local_48, (int)*(short *)*piVar6 < (int)(uint)uVar2)) ||
              ((uVar3 = *(ushort *)(iVar11 + 10 + DAT_00951bb0), uVar3 != 0 &&
               ((uVar2 <= uVar3 && ((int)(uint)uVar3 < (int)*(short *)*piVar6)))))))) {
            *piVar6 = 0;
          }
        }
        if (DAT_00803b68 != -1) {
          local_44[0] = '\0';
          iVar8 = FUN_0058a900(0);
          if (iVar8 == 0) {
            if (((*(int *)(param_1 + 0x120) != -1) &&
                ((*(byte *)(*(int *)(param_1 + 0x120) * 0x9c + 0x7a + DAT_00951354) & 0x40) != 0))
               && (DAT_0095de48 != 0)) {
              pcVar12 = "shop_start";
              goto LAB_00579dec;
            }
          }
          else {
            pcVar12 = "bounty_start";
LAB_00579dec:
            FUN_004f1f10(local_44,pcVar12);
          }
          if (((local_44[0] != '\0') &&
              (psVar9 = (short *)FUN_005d0690(iVar4,local_44), psVar9 != (short *)0x0)) &&
             ((1 < *psVar9 &&
              (*(short **)(*(int *)(param_1 + 0x2ac4) + DAT_00803b68 * 4) = psVar9,
              DAT_00803b6c != -1)))) {
            *(undefined4 *)(*(int *)(param_1 + 0x2ac4) + DAT_00803b6c * 4) = 0;
          }
        }
      }
      local_48 = iVar10 + 1;
      iVar11 = iVar11 + 0x10;
    } while (local_48 < DAT_00951bb4);
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

