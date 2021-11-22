import Vue from 'vue';
import Router from 'vue-router';
import ShopMall from '@/components/pages/shoppingMall';

Vue.use(Router);

export default new Router({
  routes: [
    {
      path: '/',
      name: 'shoppingMall',
      component: ShopMall,
    },
  ],
});
