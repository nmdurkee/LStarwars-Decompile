/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a910; label: FUN_0062a910
 */

void FUN_0062a910(size_t *param_1,void *param_2)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  
  if (((param_1 != (size_t *)0x0) && (param_2 != (void *)0x0)) && (*param_1 != 0)) {
    if (param_1 != (size_t *)0xfffffff8) {
      sVar3 = param_1[1];
      iVar2 = 0x40;
      do {
        if ((*(byte *)(sVar3 + 0x1fc) & 1) != 0) {
          FUN_0062a8c0(param_1,sVar3,param_2);
        }
        sVar3 = sVar3 + *param_1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      bVar1 = *(byte *)((int)param_2 + 0x28d);
      param_1[(uint)bVar1 * 2 + 2] = 0;
      param_1[(uint)bVar1 * 2 + 3] = 0;
    }
    _memset(param_2,0,*param_1);
  }
  return;
}

