/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5af720; label: FUN_005af720
 */

undefined4 FUN_005af720(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x5110), iVar1 == 0)) {
    return 0;
  }
  cVar2 = FUN_006218c0();
  cVar3 = FUN_006218c0();
  iVar4 = (int)cVar3;
  if (0 < iVar4) {
    do {
      FUN_00621900(iVar1);
      fVar6 = (float10)FUN_006217a0();
      *(float *)(iVar1 + 0xc) = (float)fVar6;
      if (cVar2 < '\x02') {
        *(undefined4 *)(iVar1 + 0x10) = 0x40000000;
        fVar6 = (float10)0.5;
      }
      else {
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x10) = (float)fVar6;
        fVar6 = (float10)FUN_006217a0();
      }
      *(float *)(iVar1 + 0x14) = (float)fVar6;
      if (cVar2 < '\x03') {
        *(undefined4 *)(iVar1 + 0x18) = 0x3a03126f;
        fVar6 = (float10)0.01;
      }
      else {
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x18) = (float)fVar6;
        fVar6 = (float10)FUN_006217a0();
      }
      *(float *)(iVar1 + 0x1c) = (float)fVar6;
      if (cVar2 < '\x04') {
        fVar6 = (float10)22.0;
      }
      else {
        fVar6 = (float10)FUN_006217a0();
      }
      *(float *)(iVar1 + 0x20) = (float)fVar6;
      if ('\x04' < cVar2) {
        FUN_006217a0();
        FUN_006217a0();
      }
      if ('\x05' < cVar2) {
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x24) = (float)fVar6;
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x28) = (float)fVar6;
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x2c) = (float)fVar6;
      }
      if ('\x06' < cVar2) {
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar1 + 0x30) = (float)fVar6;
      }
      if (cVar2 < '\b') {
        if (*(int *)(param_1 + 300) != 0) {
          iVar5 = ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 1) != 0) + 1;
          goto LAB_005af82b;
        }
      }
      else {
        iVar5 = FUN_006217e0();
LAB_005af82b:
        *(int *)(iVar1 + 0x34) = iVar5;
      }
      FUN_005af650();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 1;
}

