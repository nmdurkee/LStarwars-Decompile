/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6ea6cf; label: FUN_006ea6cf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006ea6cf(undefined4 param_1,undefined4 param_2)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  double dVar6;
  int local_8;
  
  uVar2 = __ctrlfp(0x133f,0xffff);
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype(param_1,(int)(CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) >>
                                  0x20));
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        goto LAB_006ea7ab;
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar1 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) + 1.0;
    dVar6 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    uVar5 = 8;
  }
  else {
    dVar6 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    if (dVar6 != 0.0) {
      FUN_006f98f5(param_1,(int)((ulonglong)dVar6 >> 0x20),&local_8);
      dVar6 = (double)(local_8 + -1);
      param_1 = SUB84(dVar6,0);
      param_2._0_2_ = (undefined2)((ulonglong)dVar6 >> 0x20);
      param_2._2_2_ = (ushort)((ulonglong)dVar6 >> 0x30);
      __ctrlfp(uVar2,0xffff);
LAB_006ea7ab:
      return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    dVar1 = -_DAT_00829f40;
    uVar5 = 4;
  }
  fVar4 = (float10)__except1(uVar5,0x25,dVar6,dVar1,uVar2);
  return fVar4;
}

