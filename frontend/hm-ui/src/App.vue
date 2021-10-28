<template>
  <div id="app">
    <div class="row">
      <hm-button>按钮</hm-button>
      <hm-button type="primary">按钮</hm-button>
      <hm-button type="success">按钮</hm-button>
      <hm-button type="info">按钮</hm-button>
      <hm-button type="warning">按钮</hm-button>
      <hm-button type="danger">按钮</hm-button>
    </div>
    <div class="row">
      <hm-button>按钮</hm-button>
      <hm-button plain type="primary">按钮</hm-button>
      <hm-button plain type="success">按钮</hm-button>
      <hm-button plain type="info">按钮</hm-button>
      <hm-button plain type="warning">按钮</hm-button>
      <hm-button plain type="danger">按钮</hm-button>
    </div>
    <div class="row">
      <hm-button>按钮</hm-button>
      <hm-button plain round type="primary">按钮</hm-button>
      <hm-button plain round type="success">按钮</hm-button>
      <hm-button plain round type="info">按钮</hm-button>
      <hm-button plain round type="warning">按钮</hm-button>
      <hm-button plain round type="danger">按钮</hm-button>
    </div>
    <div class="row">
      <hm-button>按</hm-button>
      <hm-button plain cricle type="primary">按</hm-button>
      <hm-button plain cricle type="success">按</hm-button>
      <hm-button plain cricle type="info">按</hm-button>
      <hm-button plain cricle type="warning">按</hm-button>
      <hm-button plain cricle icon="delete"></hm-button>
    </div>
  </div>
</template>

<script>
import hmButton from './components/button/button';

export default {
  name: 'App',
  components: {
    hmButton,
  },
};
</script>

<style lang="scss" scoped>
.row {
  margin-bottom: 20px;
  .hm-button {
    margin-left: 20px;
  }
}
</style>
