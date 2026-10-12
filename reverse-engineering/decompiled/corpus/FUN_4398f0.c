/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x4398f0; label: FUN_004398f0
 */

undefined4
FUN_004398f0(int *param_1,int *param_2,float param_3,uint param_4,uint param_5,float param_6,
            float param_7)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((DAT_00876cc8 != 0) && (((param_1[0x7e] & 0x400U) == 0 || ((param_2[0x7e] & 0x400U) == 0)))) {
    return 0;
  }
  uVar2 = __allshl();
  uVar1 = (uint)((ulonglong)uVar2 >> 0x20);
  if ((((uint)uVar2 & param_4) == 0 && (uVar1 & param_5) == 0) &&
     (((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                 (uint)*(byte *)((int)param_1 + 0x28d) * 8) & (uint)uVar2) == 0 &&
       (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                 (uint)*(byte *)((int)param_1 + 0x28d) * 8) & uVar1) == 0 ||
      ((((param_1[0x7f] & 0x800U) == 0 &&
        (*(float *)(*param_1 + 0xf38) * param_7 + *(float *)(*param_1 + 0xf30) * param_6 < 0.0)) &&
       (((float)param_1[0x8d] <= param_3 || ((*(uint *)(*param_2 + 0xeec) & 0x800) == 0)))))))) {
    return 0;
  }
  return 1;
}

