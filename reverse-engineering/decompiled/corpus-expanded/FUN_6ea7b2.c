/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6ea7b2; label: FUN_006ea7b2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006ea7b2(int param_1,uint param_2,int param_3,uint param_4)

{
  double dVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  double dVar8;
  undefined8 local_10;
  undefined4 local_8;
  
  local_10 = 0.0;
  local_8 = __ctrlfp();
  if (((param_2._2_2_ & 0x7ff0) == 0x7ff0) || ((param_4._2_2_ & 0x7ff0) == 0x7ff0)) {
    if ((((param_2._2_2_ & 0x7ff8) == 0x7ff0) && (((param_2 & 0x7ffff) != 0 || (param_1 != 0)))) ||
       (((param_4._2_2_ & 0x7ff8) == 0x7ff0 && (((param_4 & 0x7ffff) != 0 || (param_3 != 0)))))) {
      dVar8 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) +
              (double)CONCAT26(param_4._2_2_,CONCAT24((undefined2)param_4,param_3));
      uVar7 = CONCAT26(param_4._2_2_,CONCAT24((undefined2)param_4,param_3));
      uVar6 = CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
      uVar5 = 8;
      goto LAB_006ea845;
    }
    if (((param_2._2_2_ & 0x7ff8) == 0x7ff8) || ((param_4._2_2_ & 0x7ff8) == 0x7ff8)) {
      fVar4 = (float10)__handle_qnan2();
      return fVar4;
    }
  }
  dVar8 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  dVar1 = (double)CONCAT26(param_4._2_2_,CONCAT24((undefined2)param_4,param_3));
  if (dVar1 == dVar8) {
    __ctrlfp();
    return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  }
  if (dVar8 == 0.0) {
    if (dVar1 <= dVar8) {
      local_10 = -4.94065645841247e-324;
    }
    else {
      local_10 = 4.94065645841247e-324;
    }
  }
  if (((0.0 < dVar8) && (dVar1 < dVar8)) || ((dVar8 < 0.0 && (dVar8 < dVar1)))) {
    iVar3 = param_1 + -1;
    local_10 = (double)CONCAT44(param_2,iVar3);
    if (param_1 == 0) {
      iVar2 = param_2 - 1;
LAB_006ea902:
      local_10 = (double)CONCAT44(iVar2,(int)local_10);
    }
  }
  else if (((0.0 < dVar8) && (dVar8 < dVar1)) || ((dVar8 < 0.0 && (dVar1 < dVar8)))) {
    iVar3 = param_1 + 1;
    local_10 = (double)CONCAT44(param_2,iVar3);
    if (iVar3 == 0) {
      iVar2 = param_2 + 1;
      goto LAB_006ea902;
    }
  }
  else {
    iVar3 = (int)local_10;
  }
  if ((((ulonglong)local_10 & 0x7ff0000000000000) == 0) &&
     ((((ulonglong)local_10 & 0xfffff00000000) != 0 || (iVar3 != 0)))) {
    fVar4 = (float10)FUN_006f98f5(local_10,(int)&local_10 + 4);
    fVar4 = (float10)__set_exp((double)fVar4,local_10._4_4_ + 0x600);
    dVar8 = (double)fVar4;
    uVar7 = CONCAT26(param_4._2_2_,CONCAT24((undefined2)param_4,param_3));
    uVar6 = CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    uVar5 = 0x12;
  }
  else {
    if (((local_10._4_4_ != 0x7ff00000) || (iVar3 != 0)) &&
       ((local_10._4_4_ != -0x100000 || (iVar3 != 0)))) {
      __ctrlfp();
      return (float10)local_10;
    }
    fVar4 = (float10)FUN_006f98f5(local_10,(int)&local_10 + 4);
    fVar4 = (float10)__set_exp((double)fVar4,local_10._4_4_ + -0x600);
    dVar8 = (double)fVar4;
    uVar7 = CONCAT26(param_4._2_2_,CONCAT24((undefined2)param_4,param_3));
    uVar6 = CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    uVar5 = 0x11;
  }
LAB_006ea845:
  fVar4 = (float10)__except2(uVar5,0x26,uVar6,uVar7,dVar8,local_8);
  return fVar4;
}

