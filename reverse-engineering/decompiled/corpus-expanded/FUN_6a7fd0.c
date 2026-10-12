/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a7fd0; label: FUN_006a7fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_006a7fd0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *_Memory;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint *puVar6;
  int iVar7;
  uint local_84 [33];
  
  iVar7 = param_3;
  if (param_3 == 0) {
    iVar7 = param_2;
  }
  _Memory = _malloc(iVar7 * 4);
  _memset(local_84,0,0x84);
  iVar7 = 0;
  puVar6 = _Memory;
  if (0 < param_2) {
    do {
      iVar1 = *(int *)(param_1 + iVar7 * 4);
      if (iVar1 < 1) {
        if (param_3 == 0) {
          puVar6 = puVar6 + 1;
        }
      }
      else {
        uVar4 = local_84[iVar1];
        if ((iVar1 < 0x20) && (uVar4 >> ((byte)iVar1 & 0x1f) != 0)) {
          _free(_Memory);
          return (uint *)0x0;
        }
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        iVar3 = iVar1;
        do {
          if ((local_84[iVar3] & 1) != 0) {
            if (iVar3 == 1) {
              local_84[1] = local_84[1] + 1;
            }
            else {
              local_84[iVar3] = local_84[iVar3 + -1] * 2;
            }
            break;
          }
          local_84[iVar3] = local_84[iVar3] + 1;
          iVar3 = iVar3 + -1;
        } while (0 < iVar3);
        while ((iVar3 = iVar1 + 1, iVar3 < 0x21 && (uVar2 = local_84[iVar3], uVar2 >> 1 == uVar4)))
        {
          local_84[iVar3] = local_84[iVar1] * 2;
          uVar4 = uVar2;
          iVar1 = iVar3;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_2);
  }
  iVar7 = 0;
  puVar6 = _Memory;
  if (0 < param_2) {
    do {
      iVar1 = *(int *)(param_1 + iVar7 * 4);
      uVar4 = 0;
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          bVar5 = (byte)iVar3;
          iVar3 = iVar3 + 1;
          uVar4 = uVar4 * 2 | *puVar6 >> (bVar5 & 0x1f) & 1;
        } while (iVar3 < iVar1);
      }
      if ((param_3 == 0) || (iVar1 != 0)) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_2);
  }
  return _Memory;
}

