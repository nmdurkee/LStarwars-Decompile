/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561020; label: FUN_00561020
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00561020(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  undefined1 uStack_4;
  
  pfVar4 = (float *)&DAT_00947c90;
  iVar5 = 0x80;
  do {
    if (*(char *)(pfVar4 + 10) != '\0') {
      if (*(char *)((int)pfVar4 + 0x2a) == '\0') {
        if (((uint)pfVar4[2] & 0x80) != 0) {
          *(undefined1 *)((int)pfVar4 + 0x2a) = 1;
          pfVar4[-4] = 1.0;
          pfVar4[-5] = 1.0;
        }
        if (*pfVar4 <= 0.0) {
          if (pfVar4[-5] < pfVar4[-4]) {
            fVar2 = pfVar4[-5] + _DAT_00925018;
            pfVar4[-5] = fVar2;
            if (pfVar4[-4] < fVar2 != (pfVar4[-4] == fVar2)) {
              pfVar4[-5] = pfVar4[-4];
              *(undefined1 *)((int)pfVar4 + 0x2a) = 1;
              if (((code *)pfVar4[0x10] != (code *)0x0) && (*(char *)((int)pfVar4 + 0x2f) != '\0'))
              {
                (*(code *)pfVar4[0x10])(pfVar4 + -0x34);
              }
            }
            fVar2 = pfVar4[2];
            if (((uint)fVar2 & 0x50) != 0) {
              fVar1 = pfVar4[-5] / pfVar4[-4];
              if (((uint)fVar2 & 0x100) == 0) {
                if ((((uint)fVar2 & 0x200) == 0) && (((uint)fVar2 & 0x400) == 0)) {
                  if (((uint)fVar2 & 0x800) != 0) goto LAB_00561170;
                }
                else {
                  iVar3 = FUN_006e6b90();
                  fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
                }
              }
              else {
LAB_00561170:
                iVar3 = FUN_006e6b90();
                fVar1 = 1.0 - (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
              }
              if (((uint)fVar2 & 0x10) != 0) {
                pfVar4[-0xf] = (pfVar4[-0x12] - pfVar4[-0x15]) * fVar1 + pfVar4[-0x15];
                pfVar4[-0xe] = (pfVar4[-0x11] - pfVar4[-0x14]) * fVar1 + pfVar4[-0x14];
                pfVar4[-0xd] = (pfVar4[-0x10] - pfVar4[-0x13]) * fVar1 + pfVar4[-0x13];
              }
              if (((uint)fVar2 & 0x40) != 0) {
                pfVar4[-7] = (pfVar4[-8] - pfVar4[-9]) * fVar1 + pfVar4[-9];
              }
            }
            if (((uint)fVar2 & 0x8000) == 0) {
              if (((uint)fVar2 & 0x4000) != 0) {
                uStack_4 = (undefined1)(int)ROUND((1.0 - pfVar4[-5] / pfVar4[-4]) * 128.0);
                *(undefined1 *)((int)pfVar4 + 0x27) = uStack_4;
              }
            }
            else {
              iVar3 = FUN_006e6b90();
              uStack_4 = (undefined1)(int)ROUND((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * 128.0)
              ;
              *(undefined1 *)((int)pfVar4 + 0x27) = uStack_4;
            }
            if ((code *)pfVar4[0xd] != (code *)0x0) {
              (*(code *)pfVar4[0xd])(pfVar4 + -0x34);
            }
          }
        }
        else {
          fVar2 = *pfVar4 - _DAT_00925018;
          *pfVar4 = fVar2;
          if ((fVar2 < 0.0 != (fVar2 == 0.0)) && ((code *)pfVar4[0xc] != (code *)0x0)) {
            (*(code *)pfVar4[0xc])(pfVar4 + -0x34);
          }
        }
      }
      else {
        *(undefined1 *)(pfVar4 + 10) = 0;
        if (((code *)pfVar4[0x10] != (code *)0x0) && (*(char *)((int)pfVar4 + 0x2f) == '\0')) {
          (*(code *)pfVar4[0x10])(pfVar4 + -0x34);
        }
      }
    }
    pfVar4 = pfVar4 + 0x45;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

