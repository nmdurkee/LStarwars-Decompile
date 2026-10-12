/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52c000; label: FUN_0052c000
 */

void FUN_0052c000(int param_1)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  void *_Dst;
  void *local_10;
  
  if (DAT_0092222c != 0) {
    iVar2 = *DAT_00922214;
    if ((DAT_00922218 == (uint *)0x0) || (*DAT_00922218 <= iVar2 + 0x24U)) {
      FUN_00512850();
      return;
    }
    puVar8 = (undefined4 *)(iVar2 + 0xfU & 0xfffffff0);
    *DAT_00922214 = (iVar2 + 0xfU & 0xfffffff0) + 0x24;
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar8[4] = 0;
    puVar8[5] = 0;
    puVar8[6] = 0;
    puVar8[7] = 0;
    puVar8[8] = 0;
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[6] = 0;
      puVar8[7] = 0;
      puVar8[8] = 0;
      while (iVar5 = FUN_004fc5b0(param_1), iVar5 != 0) {
        while (iVar5 = FUN_004f7fb0(param_1), iVar5 != 0) {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
          if (iVar5 == 0) goto LAB_0052c2d9;
          iVar5 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Script");
          puVar4 = DAT_00922218;
          piVar3 = DAT_00922214;
          if (iVar5 == 0) {
            iVar5 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"ReturnState");
            puVar4 = DAT_00922218;
            piVar3 = DAT_00922214;
            if (iVar5 == 0) {
              iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"CONDITIONS");
              if (iVar5 == 0) {
                DAT_00922230 = puVar8 + 7;
                DAT_00922238 = 1;
                FUN_0052b3f0(param_1);
                DAT_00922230 = (undefined4 *)0x0;
                DAT_00922238 = 0;
              }
              else {
                iVar5 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Source");
                if (iVar5 != 0) {
                  iVar5 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Global");
                  if (iVar5 == 0) {
                    iVar5 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Level");
                    if (iVar5 != 0) {
                      puVar8[6] = puVar8[6] | 2;
                    }
                  }
                  else {
                    puVar8[6] = puVar8[6] | 1;
                  }
                }
              }
            }
            else {
              iVar5 = iVar5 + 0xc;
              _Dst = (void *)0x0;
              if ((iVar5 != 0) && (iVar6 = FUN_004f1ff0(iVar5), iVar6 != 0)) {
                sVar1 = iVar6 + 1;
                if ((piVar3 == (int *)0x0) || (puVar4 == (uint *)0x0)) {
                  FUN_00512850();
                }
                else if (*piVar3 + sVar1 < *puVar4) {
                  uVar7 = *piVar3 + 0xf;
                  _Dst = (void *)(uVar7 & 0xfffffff0);
                  *piVar3 = (uVar7 & 0xfffffff0) + sVar1;
                  _memset(_Dst,0,sVar1);
                }
                else {
                  FUN_00512850();
                }
                FUN_004f1f10(_Dst,iVar5);
              }
              puVar8[4] = _Dst;
            }
          }
          else {
            iVar5 = iVar5 + 7;
            local_10 = (void *)0x0;
            if ((iVar5 != 0) && (iVar6 = FUN_004f1ff0(iVar5), iVar6 != 0)) {
              local_10 = (void *)0x0;
              sVar1 = iVar6 + 1;
              if ((piVar3 == (int *)0x0) || (puVar4 == (uint *)0x0)) {
                FUN_00512850();
              }
              else if (*piVar3 + sVar1 < *puVar4) {
                uVar7 = *piVar3 + 0xf;
                local_10 = (void *)(uVar7 & 0xfffffff0);
                *piVar3 = (uVar7 & 0xfffffff0) + sVar1;
                _memset(local_10,0,sVar1);
              }
              else {
                FUN_00512850();
              }
              FUN_004f1f10(local_10,iVar5);
            }
            puVar8[2] = local_10;
          }
        }
      }
LAB_0052c2d9:
      if (puVar8[2] != 0) {
        if ((puVar8[6] & 3) == 0) {
          puVar8[6] = puVar8[6] | 3;
        }
        FUN_004f1310(DAT_0092222c,puVar8);
        return;
      }
      FUN_00512860();
      *DAT_00922214 = iVar2;
    }
  }
  return;
}

