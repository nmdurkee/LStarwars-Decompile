/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ee990; label: FUN_004ee990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ee990(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  
  iVar1 = DAT_0088ab0c;
  iVar5 = 0;
  iVar7 = 0;
  pfVar4 = (float *)0x0;
  if (DAT_0088ab0c != 0) {
    piVar6 = &DAT_0093d7f0;
    do {
      iVar2 = *piVar6;
      if ((((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
            (*(char *)(iVar2 + 0x28b) == '\0')) &&
           (((char)*(uint *)(iVar2 + 0x1fc) < '\0' &&
            (pfVar4 = (float *)(iVar2 + 0x80), -57.0 <= *(float *)(iVar2 + 0x80))))) &&
          ((*pfVar4 <= -47.0 &&
           ((-5.2 <= *(float *)(iVar2 + 0x88) && (*(float *)(iVar2 + 0x88) <= -4.22)))))) &&
         (iVar5 = iVar5 + 1, iVar7 = iVar2, 1 < iVar5)) {
        return;
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x93d810);
    if (iVar7 != 0) {
      *(float *)(DAT_0088ab0c + 0x10) = *pfVar4;
      *(float *)(iVar1 + 0x14) = pfVar4[1];
      *(float *)(iVar1 + 0x18) = pfVar4[2];
      if (1.1 <= *(float *)(iVar7 + 0x84)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x3fc00000;
      }
      *(undefined4 *)(iVar1 + 0x14) = uVar3;
      fVar8 = (float10)FUN_005506f0(0,iVar1 + 0x10,0x3e4ccccd,0xffffffff);
      iVar7 = DAT_0088ab0c;
      *(float *)(DAT_0088ab0c + 0x14) = (float)fVar8;
      iVar1 = iVar7 + 0x10;
      FUN_0043e040(*(undefined4 *)(param_1 + 0x2ae8),iVar1,iVar7 + 0x20,iVar1,0,0xff);
      return;
    }
  }
  return;
}

