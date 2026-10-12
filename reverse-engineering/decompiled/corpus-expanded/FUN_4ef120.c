/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef120; label: FUN_004ef120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004ef120(int param_1,uint param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  void *pvVar8;
  
  iVar1 = DAT_0088ab20;
  if (DAT_0088ab28 != 0) {
    puVar4 = (undefined4 *)FUN_004eeda0();
    *(uint *)*puVar4 = *(uint *)*puVar4 + 0xf & 0xfffffff0;
    piVar3 = (int *)*puVar4;
    if (param_2 <= (uint)(puVar4[1] - *piVar3)) {
      puVar4 = (undefined4 *)*piVar3;
      *piVar3 = *piVar3 + param_2;
      return puVar4;
    }
    return (undefined4 *)0x0;
  }
  if (DAT_0088ab20 == 0) {
    puVar4 = (undefined4 *)(param_1 + -0x20);
    if (*(int *)(param_1 + -0x20) != 0) {
      *(undefined4 *)(*(int *)(param_1 + -0x20) + 4) = *(undefined4 *)(param_1 + -0x1c);
    }
    pvVar8 = DAT_0088ab18;
    if (*(undefined4 **)(param_1 + -0x1c) == (undefined4 *)0x0) {
      pvVar8 = (void *)*puVar4;
      DAT_0088ab18 = pvVar8;
    }
    else {
      **(undefined4 **)(param_1 + -0x1c) = *puVar4;
    }
    pcVar5 = param_3;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    puVar4 = _realloc(puVar4,(size_t)(pcVar5 + param_2 + (0x2d - (int)(param_3 + 1))));
    if (puVar4 == (void *)0x0) {
      puVar6 = (undefined4 *)FUN_004eedc0(param_2,param_3,param_4);
    }
    else {
      iVar1 = puVar4[4];
      puVar4[4] = param_2;
      DAT_0088ab1c = DAT_0088ab1c + (param_2 - iVar1);
      *(undefined4 *)((int)puVar4 + param_2 + 0x20) = s_MEMBLKTAIL01_00800454._0_4_;
      *(undefined4 *)((int)puVar4 + param_2 + 0x24) = s_MEMBLKTAIL01_00800454._4_4_;
      *(undefined4 *)((int)puVar4 + param_2 + 0x28) = s_MEMBLKTAIL01_00800454._8_4_;
      iVar1 = (param_2 + 0x2c) - (int)param_3;
      do {
        cVar2 = *param_3;
        param_3[(int)puVar4 + iVar1] = cVar2;
        param_3 = param_3 + 1;
      } while (cVar2 != '\0');
      puVar4[2] = param_4;
      *puVar4 = pvVar8;
      if (pvVar8 != (void *)0x0) {
        *(undefined4 **)((int)pvVar8 + 4) = puVar4;
      }
      puVar4[1] = 0;
      puVar6 = puVar4 + 8;
      DAT_0088ab18 = puVar4;
    }
    iVar1 = (int)puVar6 + param_2;
    if (DAT_0088ab30 < iVar1) {
      DAT_0088ab30 = iVar1;
    }
    if (DAT_0088ab34 < iVar1) {
      DAT_0088ab34 = iVar1;
    }
    return puVar6;
  }
  piVar3 = (int *)(DAT_0088ab20 + 4);
  uVar7 = param_2 + 0xf & 0xfffffff0;
  if ((int)uVar7 < *piVar3) {
    puVar4 = *(undefined4 **)(DAT_0088ab20 + 8);
    *(uint *)(DAT_0088ab20 + 8) = (int)puVar4 + uVar7;
    *(uint *)(iVar1 + 4) = *piVar3 - uVar7;
    return puVar4;
  }
  return (undefined4 *)0x0;
}

