/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6326b0; label: FUN_006326b0
 */

void FUN_006326b0(float param_1)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1 < 0.9999) || (in_EAX[3] != 0)) {
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x1b,1);
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x13,5);
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x14,6);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,4,4);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,2,2);
    uVar2 = 0;
    uVar1 = 3;
  }
  else {
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x1b,0);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,4,2);
    uVar2 = 2;
    uVar1 = 2;
  }
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,uVar1,uVar2);
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,5,2);
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,1,4);
  return;
}

