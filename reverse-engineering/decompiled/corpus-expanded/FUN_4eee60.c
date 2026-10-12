/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4eee60; label: FUN_004eee60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_004eee60(uint param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  uint uVar5;
  
  puVar3 = DAT_0088ab28;
  iVar1 = DAT_0088ab20;
  if (DAT_0088ab28 != (undefined4 *)0x0) {
    *(uint *)*DAT_0088ab28 = *(uint *)*DAT_0088ab28 + 0xf & 0xfffffff0;
    piVar2 = (int *)*puVar3;
    if (param_1 <= (uint)(puVar3[1] - *piVar2)) {
      pvVar4 = (void *)*piVar2;
      *piVar2 = *piVar2 + param_1;
      return pvVar4;
    }
    return (void *)0x0;
  }
  if (DAT_0088ab20 == 0) {
    DAT_0088ab1c = DAT_0088ab1c + param_1;
    if (DAT_0088ab2c == 0) {
      pvVar4 = _malloc(param_1);
    }
    else {
      pvVar4 = (void *)FUN_004f6740(DAT_0088ab2c,param_1,4);
    }
    _memset(pvVar4,0,param_1);
    iVar1 = (int)pvVar4 + param_1;
    if (DAT_0088ab30 < iVar1) {
      DAT_0088ab30 = iVar1;
    }
    if (DAT_0088ab34 < iVar1) {
      DAT_0088ab34 = iVar1;
    }
    return pvVar4;
  }
  piVar2 = (int *)(DAT_0088ab20 + 4);
  uVar5 = param_1 + 0xf & 0xfffffff0;
  if ((int)uVar5 < *piVar2) {
    pvVar4 = *(void **)(DAT_0088ab20 + 8);
    *(uint *)(DAT_0088ab20 + 8) = (int)pvVar4 + uVar5;
    *(uint *)(iVar1 + 4) = *piVar2 - uVar5;
    return pvVar4;
  }
  return (void *)0x0;
}

