/* Ghidra pseudocode, not original source.
 * ev_9238a7d4a32c49ce947fe3ed44bc206dac4b982bd913cd0b1074936c5e6922ce
 * Entry: 0x57a000; label: FUN_0057a000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057a000(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  size_t _Size;
  int iVar8;
  
  iVar3 = param_1;
  uVar5 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x104) = uVar5;
  *(uint *)(param_1 + 0x2ac0) = uVar5;
  _Size = DAT_00951bbc * 0x10;
  *(uint *)(param_1 + 0x104) = uVar5 + _Size;
  _memset(*(void **)(param_1 + 0x2ac0),0,_Size);
  if ((DAT_00951bb8 != 0) && (iVar8 = 0, 0 < DAT_00951bbc)) {
    param_1 = 0;
    do {
      iVar6 = FUN_004f8b10(*(undefined4 *)(DAT_00951bb8 + 4 + iVar8 * 8),"power_up");
      if (iVar6 == 0) {
        _DAT_00803d88 = iVar8;
      }
      bVar1 = false;
      bVar2 = false;
      switch(*(undefined1 *)(DAT_00951bb8 + iVar8 * 8)) {
      case 1:
        iVar6 = *(int *)(iVar3 + 0x13c);
        break;
      case 2:
        iVar6 = DAT_0092489c;
        if (DAT_0092489c == 0) {
          iVar6 = *(int *)(iVar3 + 0x13c);
        }
        break;
      case 3:
        iVar6 = 0;
        do {
          if (DAT_0093b278 <= iVar6) {
            if (!bVar1) {
              iVar6 = DAT_009248a0;
              if (DAT_009248a0 != 0) goto LAB_0057a1d3;
              iVar6 = *(int *)(iVar3 + 0x2964);
              goto LAB_0057a1cf;
            }
            break;
          }
          iVar7 = FUN_0055b6c0(iVar6);
          if ((iVar7 != 0) &&
             (iVar7 = FUN_005cf5b0(iVar7,*(int *)(iVar3 + 0x2ac0) + param_1,
                                   *(undefined4 *)(DAT_00951bb8 + 4 + iVar8 * 8),1), iVar7 != 0)) {
            bVar1 = true;
          }
          iVar6 = iVar6 + 1;
        } while (!bVar1);
        goto LAB_0057a12e;
      case 4:
        iVar6 = DAT_00924888;
        break;
      case 5:
        iVar6 = DAT_00924898;
        break;
      default:
        iVar6 = DAT_00924880;
        if (((DAT_0092489c != 0) && (*(int *)(iVar3 + 300) != 0)) &&
           ((*(ushort *)(*(int *)(iVar3 + 300) + 0x7a) & 0x400) != 0)) {
          bVar2 = true;
          iVar6 = DAT_0092489c;
        }
      }
LAB_0057a1cf:
      if (iVar6 != 0) {
LAB_0057a1d3:
        iVar6 = FUN_005cf5b0(iVar6,*(int *)(iVar3 + 0x2ac0) + param_1,
                             *(undefined4 *)(DAT_00951bb8 + 4 + iVar8 * 8),1);
        if ((iVar6 == 0) && (bVar2)) {
          FUN_005cf5b0(DAT_00924880,*(int *)(iVar3 + 0x2ac0) + param_1,
                       *(undefined4 *)(DAT_00951bb8 + 4 + iVar8 * 8),1);
        }
LAB_0057a12e:
        uVar4 = FUN_005cfac0(*(int *)(iVar3 + 0x2ac0) + param_1);
        *(undefined1 *)(param_1 + 0xe + *(int *)(iVar3 + 0x2ac0)) = uVar4;
        iVar6 = *(int *)(iVar3 + 0x2ac0) + param_1;
        if (*(char *)(iVar6 + 0xe) != '\0') {
          FUN_005cfc00(iVar6,0);
        }
      }
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 0x10;
    } while (iVar8 < DAT_00951bbc);
  }
  return;
}

