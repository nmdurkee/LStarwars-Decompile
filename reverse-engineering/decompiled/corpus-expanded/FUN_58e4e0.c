/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e4e0; label: FUN_0058e4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058e4e0(float param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = (int)param_1;
  *(uint *)((int)param_1 + 0x7bc) = *(uint *)((int)param_1 + 0x7bc) | 0x40;
  iVar8 = 0;
  if (((DAT_00802848 != -1) && (*(char *)((int)param_1 + 0x7b5) == DAT_00802848)) &&
     (iVar5 = *(int *)(*(int *)((int)param_1 + 0x50) + 8),
     *(int *)(iVar5 + *(short *)((int)param_1 + 0x7aa) * 4) != 0)) {
    *(undefined1 *)((int)param_1 + 0xe3e) =
         *(undefined1 *)(*(int *)(iVar5 + *(short *)((int)param_1 + 0x7aa) * 4) + 0x4a);
  }
  if (param_2 == 0) {
    iVar5 = *(int *)((int)param_1 + 0x794);
    if ((((iVar5 == 0) || (uVar7 = *(uint *)(iVar5 + 0x94), (uVar7 & 1) != 0)) ||
        (((uVar7 & 0x4000) == 0 ||
         (((uVar7 & 0x800000) == 0 || (*(float *)((int)param_1 + 0x188) < *(float *)(iVar5 + 0x5c)))
         )))) || (*(float *)(iVar5 + 0x68) < *(float *)((int)param_1 + 0x17c))) goto LAB_0058e8c0;
    iVar8 = iVar5 + 0x4c;
    iVar5 = FUN_00567800(iVar5,1,1,1,0,1);
    if (iVar5 != 0) {
      FUN_0054a8a0(**(undefined4 **)((int)param_1 + 0xca4),0x3dcccccd,0);
    }
    FUN_0054a850(**(undefined4 **)((int)param_1 + 0xca4),0x3f000000,0);
LAB_0058e8a2:
    if (iVar8 != 0) {
      *(uint *)(iVar2 + 0xe24) = *(uint *)(iVar2 + 0xe24) | 0x100;
      if ((*(byte *)(iVar2 + 0x1fc) & 0x80) != 0) {
        FUN_00549f10();
      }
      goto LAB_0058e8ca;
    }
  }
  else {
    uVar7 = *(uint *)(param_2 + 0x1fc);
    if (((((uVar7 & 1) == 0) || ((uVar7 & 0x1000) == 0)) || (*(char *)(param_2 + 0x28b) != '\0')) ||
       ((*(float *)((int)param_1 + 0x188) < *(float *)(param_2 + 0x17c) ||
        (*(float *)(param_2 + 0x188) < *(float *)((int)param_1 + 0x17c))))) goto LAB_0058e8c0;
    if ((DAT_00802820 != -1) && (*(char *)(param_2 + 0x7b5) == DAT_00802820)) {
      FUN_0058dfa0(param_2);
      iVar8 = param_2 + 0x80;
      if (DAT_009555a4 != (code *)0x0) {
        (*DAT_009555a4)(param_1,param_2);
      }
      goto LAB_0058e8a2;
    }
    if ((-1 < (char)uVar7) ||
       (((DAT_00802848 == -1 || (*(char *)(param_2 + 0x7b5) != DAT_00802848)) &&
        ((DAT_00802838 == -1 ||
         ((*(char *)(param_2 + 0x7b5) != DAT_00802838 || (*(char *)((int)param_1 + 0x7b8) != '\x03')
          ))))))) {
      iVar5 = FUN_0058d340(param_1,param_2,param_4);
      if (iVar5 != 0) {
        iVar5 = 1;
        if (DAT_0095559c == (code *)0x0) {
LAB_0058e642:
          iVar6 = FUN_0056e0f0(0x800);
          if (iVar6 != 0) {
            iVar5 = iVar5 * 2;
          }
        }
        else {
          iVar5 = (*DAT_0095559c)(param_1,param_2);
          if (iVar5 != -1) goto LAB_0058e642;
        }
        uVar7 = *(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_2 + 0x7b5) * 0x10 + 8);
        if ((uVar7 & 0x80) == 0) {
          if (((uVar7 & 0x4000000) == 0) &&
             (((uVar7 & 0xc000000) == 0 || ((*(uint *)(param_2 + 0x7bc) & 0x20000) == 0)))) {
            iVar8 = FUN_0058b7f0(param_2);
            if (iVar8 != 0) goto LAB_0058e6d0;
            uVar7 = FUN_0058b720(param_1,0,1);
            FUN_00438230(param_1,param_2,iVar5,uVar7 | 0x40);
          }
          else {
LAB_0058e6d0:
            FUN_0054a850(**(undefined4 **)((int)param_1 + 0xca4),0x3f000000,0);
            FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f000000,0);
            if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_2 + 0x7b5) * 0x10 + 8) & 0x80000000)
                == 0) {
              uVar3 = FUN_005be2d0(*(float *)((int)param_1 + 0x80) - *(float *)(param_2 + 0x80),
                                   *(float *)((int)param_1 + 0x88) - *(float *)(param_2 + 0x88));
              *(undefined2 *)(param_2 + 0x5a) = uVar3;
            }
          }
          iVar8 = param_2 + 0x80;
        }
        if ((*(byte *)(param_2 + 0x1fc) & 2) == 0) {
          fVar1 = *(float *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x1c);
          if (1.0 < *(float *)((int)param_1 + 0xa4)) {
            fVar1 = fVar1 / *(float *)((int)param_1 + 0xa4);
          }
          param_1 = fVar1;
          uVar4 = *(ushort *)(iVar2 + 0x5a);
          if ((*(byte *)(iVar2 + 0x7bc) & 0x80) != 0) {
            uVar4 = uVar4 + 0x8000;
          }
          *(float *)(param_2 + 0x68) =
               *(float *)(param_2 + 0x68) + param_1 * (float)(&DAT_029899a0)[uVar4 >> 1];
          *(float *)(param_2 + 0x70) =
               param_1 * (float)(&DAT_029899a0)[(int)(uVar4 + 0x4000) >> 1 & 0x7fff] +
               *(float *)(param_2 + 0x70);
        }
        goto LAB_0058e8a2;
      }
    }
  }
LAB_0058e8c0:
  *(uint *)(iVar2 + 0xe24) = *(uint *)(iVar2 + 0xe24) & 0xfffffeff;
LAB_0058e8ca:
  if (DAT_009555a0 != (code *)0x0) {
    (*DAT_009555a0)(iVar2,iVar8);
  }
  return;
}

