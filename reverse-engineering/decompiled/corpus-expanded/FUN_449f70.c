/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449f70; label: FUN_00449f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00449f70(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_108;
  int local_100 [32];
  int aiStack_80 [32];
  
  iVar5 = 0;
  iVar4 = 0;
  bVar1 = false;
  local_108 = 0;
  if ((in_stack_00000018 != 0) && (DAT_00876d94 = 0, 0 < in_stack_00000014)) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar5 * 4),"splines=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar5 * 4),"spline=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar5 * 4),"unused");
          if (iVar2 != 0) {
            bVar1 = true;
          }
        }
        else {
          iVar2 = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar2 + 7);
          if ((iVar2 != 0) && (iVar4 < 0x20)) {
            local_100[iVar4] = iVar2;
            iVar4 = iVar4 + 1;
          }
        }
      }
      else {
        iVar2 = FUN_005d0740(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar2 + 8,local_100 + iVar4,
                             0x20 - iVar4);
        iVar4 = iVar4 + iVar2;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < in_stack_00000014);
    if (iVar4 != 0) {
      if (bVar1) {
        iVar2 = 0;
        iVar5 = DAT_0093d500;
        if (0 < DAT_0093d500) {
          piVar3 = (int *)(DAT_0093d504 + 0xe64);
          do {
            if (((((piVar3[-0x31a] & 1U) != 0) && ((piVar3[-0x31a] & 0x1000U) != 0)) &&
                (*(char *)((int)piVar3 + -0xbd9) == '\0')) && (*piVar3 != 0)) {
              *(ushort *)*piVar3 = *(ushort *)*piVar3 | 0x8000;
              iVar5 = DAT_0093d500;
            }
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 0x436;
          } while (iVar2 < iVar5);
        }
        iVar2 = 0;
        if (0 < iVar4) {
          do {
            if ((*(ushort *)local_100[iVar2] & 0x8000) == 0) {
              aiStack_80[local_108] = local_100[iVar2];
              local_108 = local_108 + 1;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar4);
        }
        iVar4 = 0;
        if (0 < iVar5) {
          piVar3 = (int *)(DAT_0093d504 + 0xe64);
          do {
            if ((((piVar3[-0x31a] & 1U) != 0) && ((piVar3[-0x31a] & 0x1000U) != 0)) &&
               ((*(char *)((int)piVar3 + -0xbd9) == '\0' && (*piVar3 != 0)))) {
              *(ushort *)*piVar3 = *(ushort *)*piVar3 & 0x7fff;
              iVar5 = DAT_0093d500;
            }
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 0x436;
          } while (iVar4 < iVar5);
        }
        if (local_108 != 0) {
          iVar4 = FUN_0054fa60();
          DAT_00876d94 = aiStack_80[iVar4 / ((int)(0xffff / (longlong)local_108) + 1)];
        }
      }
      else {
        iVar5 = FUN_0054fa60();
        DAT_00876d94 = local_100[iVar5 / ((int)(0xffff / (longlong)iVar4) + 1)];
      }
    }
  }
  return 1;
}

